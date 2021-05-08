// 210508 #5896 효율적으로 소 사기 Platinum IV
// greedy -> is this really good solution to buy cheap cows by coupons? 
// pq: min heap -> min (coupon price -> original price) cost  
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl2;
typedef pair<pair<ll, ll>, ll> pl;
const int MAX = 50001;
ll N, K, M, ans, cost;
vector<pl> v;
bool visit[MAX];
priority_queue<pl2, vector<pl2>, greater<pl2>> pq;
bool cmp(pl p1, pl p2) {
	if (p1.first.second == p2.first.second)
		return p1.first.first < p2.first.first;
	return p1.first.second < p2.first.second;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < K; i++) {
		if (cost + v[i].first.second <= M) {
			cost += v[i].first.second;
			ans++;
			pq.push({ v[i].first.first - v[i].first.second, v[i].second });
			visit[v[i].second] = true;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (visit[v[i].second])
			continue;
		if (!pq.empty() && pq.top().first + v[i].first.second < v[i].first.first) {
			if (cost + pq.top().first + v[i].first.second <= M) {
				cost += pq.top().first + v[i].first.second;
				ans++;
				pq.pop();
				pq.push({ v[i].first.first - v[i].first.second, v[i].second });
			}
		}
		else if (cost + v[i].first.first <= M) {
			cost += v[i].first.second;
			ans++;
		}
	}
	cout << ans << "\n";
}
