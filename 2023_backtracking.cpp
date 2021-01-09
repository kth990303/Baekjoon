// 210109 #2023 신기한 소수 Gold V
// eratosthenes + backtracking (N<=8)
// O(1e8)? No, sieve can reduce time complexity.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 9;
int N;
vector<int> ans;
bool sieve(int num) {
	// o(nlgn)
	// if(num<=1) return false; -> num is bigger than 10
	for (int i = 2; i * i <= num; i++) {
		if (!(num % i))
			return false;
	}
	return true;
}
void solve(int cur, int num) {
	if (cur == N) {
		ans.push_back(num);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (sieve(num * 10 + i))
			solve(cur + 1, num * 10 + i);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	solve(1, 2);
	solve(1, 3);
	solve(1, 5);
	solve(1, 7);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}