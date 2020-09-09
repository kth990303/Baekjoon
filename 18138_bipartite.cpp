// 200909 #18138 리유나는 세일러복을 좋아해 Platinum V
// 이분매칭의 활용
// double형에 주의
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 201;
int N, M, d[MAX];
double w[MAX];	// 옷의 너비
bool used[MAX];
vector<int> v[MAX];
bool dfs(int x) {
	for (auto i : v[x]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs(d[i])) {
			d[i] = x;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= M; i++) {
		double val;
		cin >> val;
		for (int j = 1; j <= N; j++) {
			// 너비에 만족하면 매칭 가능하게
			if (w[j] * 0.5 <= val && w[j] * 0.75 >= val) {
				v[j].push_back(i);
			}
			else if (w[j] <= val && w[j] * 1.25 >= val) {
				v[j].push_back(i);
			}
		}
	}
	int ans = 0;
	// 전형적인 이분매칭
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		if (dfs(i))
			ans++;
	}
	cout << ans << "\n";
}