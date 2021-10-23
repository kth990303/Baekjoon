// 211023 #17612 ºÓ«Œ∏Ù Gold I
// priority_queue, stack
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 100011;
const double INF = 0x3f3f3f3f;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int N, K;
vector<pi> v;
struct Person {
	int id, w, n;
};
struct cmp {
	bool operator()(Person p1, Person p2) {
		if (p1.w == p2.w)
			return p1.n < p2.n;
		return p1.w > p2.w;
	}
};
priority_queue<Person, vector<Person>, cmp> pq;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		int id, w;
		cin >> id >> w;
		v.push_back({ id, w });
		if (i <= K)
			pq.push({id, w, i});
	}
	int cnt = 0, idx = K;
	vector<Person> out;;
	while(!pq.empty()) {
		while (1) {
			int id = pq.top().id;
			int w = pq.top().w;
			int n = pq.top().n;
			pq.pop();
			ans += 1LL * id * (++cnt);
			out.push_back({ id, w, n });
			if (pq.empty() || pq.top().w != w)
				break;
		}
		for (int i = out.size()-1; i >=0;i--) {
			if (pq.size() < K && idx < N) {
				pq.push({ v[idx].first, v[idx].second + out[i].w,
					out[i].n });
				idx++;
			}
			else
				break;
		}
	}
	cout << ans << "\n";
}