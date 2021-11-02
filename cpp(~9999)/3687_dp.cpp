// 210216 #3687 성냥개비 Gold II
// top-down is too difficult
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
typedef long long ll;
const ll INF = 1e18;
int N, k[10]= { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
ll d[MAX] = { 0,0,1,7,4,2,6,8,10, };
ll n[MAX] = { 0,0,1,7,4,2,0,8,10, };
// bigNum is not dp. it's greedy
string bigNum(int N, string ans2) {
	if (N % 2) {
		ans2 += "7";
		N -= k[7];
	}
	while (N) {
		ans2 += "1";
		N -= k[1];
	}
	return ans2;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	fill(d + 9, d + MAX, INF);
	for (int i = 9; i < MAX; i++) {
		for (int j = 2; j <= 7; j++) {
			// because of 0 (needs 6)
			d[i] = min(d[i], d[i - j] * 10 + n[j]);
		}
	}
	while (t--) {
		cin >> N;
		cout << d[N] << " " << bigNum(N, "") << "\n";
	}
}