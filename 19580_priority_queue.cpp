// 210816 #19580 마스크가 필요해 Platinum V
// greedy + priority_queue
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
const int MAX = 500001;
ll N, M, ans;
priority_queue<pl, vector<pl>, greater<pl>> pq1, pq2, pq3;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll L, R;
		cin >> L >> R;
		pq1.push({L, R});
	}
	for (int i = 0; i < M; i++) {
		ll P, X;
		cin >> P >> X;
		pq2.push({P, X});
	}
	while (!pq2.empty()) {
		ll L, R;
		ll P = pq2.top().first;
		ll cnt = pq2.top().second;
		pq2.pop();
		if (cnt <= 0)
			continue;
		while (!pq1.empty()) {
			L = pq1.top().first;
			R = pq1.top().second;
			if (R < P) {
				pq1.pop();
				continue;
			}
			if (P >= L) {
				pq1.pop();
				pq3.push({ R, L });
			}
			else
				break;
		}
		while (!pq3.empty() && cnt) {
			L = pq3.top().second;
			R = pq3.top().first;
			pq3.pop();
			if (L <= P && P <= R) {
				ans++;
				--cnt;
			}
		}
	}
	cout << ans << "\n";
}