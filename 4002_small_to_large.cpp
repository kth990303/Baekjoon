// 210309 #4002 닌자배치 Diamond V
// Small_to_large trick -> O(N^2) -> O(NlgN)
// O(nlog^2n)
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
typedef long long ll;
ll N, M, B[MAX], C[MAX], L[MAX], root, ans, idx[MAX];
vector<ll> v[MAX];
priority_queue<ll> pq[MAX];
ll dp(int cur) {
	ll& ret = C[cur];
	for (auto i : v[cur]) {
		ret += dp(i);
		// small to big
		if (pq[idx[cur]].size() > pq[idx[i]].size())
			swap(idx[cur], idx[i]);
		while (!pq[idx[cur]].empty()) {
			pq[idx[i]].push(pq[idx[cur]].top());
			pq[idx[cur]].pop();
		}
		// if cost > M
		while (!pq[idx[i]].empty() && ret > M) {
			ret -= pq[idx[i]].top();
			pq[idx[i]].pop();
		}
		idx[cur] = idx[i];
	}
	ans = max(ans, L[cur] * (ll)pq[idx[cur]].size());
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> B[i] >> C[i] >> L[i];
		idx[i] = i;
		if (!B[i])
			root = i;
		else
			v[B[i]].push_back(i);
		// manager can work or not
		pq[i].push(C[i]);
	}
	dp(root);
	cout << ans << "\n";
}