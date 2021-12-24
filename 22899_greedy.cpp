// 211225 #22899 ø¿∑ª¡ˆƒ≈ √‚¡¶«œ±‚ Gold II
// how manage check pq[i].not empty() idx
// two sets
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll N, a[MAX], b[MAX], ans[MAX];
int K, M;
priority_queue<ll> pq;
priority_queue<ll, vector<ll>, greater<ll>> pq2[MAX];
queue<pl> q;
unordered_set<int> S, S2;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(ans, ans + MAX, LNF);
	for (int i = 0; i < N; i++) {
		cin >> b[i];
		pq2[a[i]].push(b[i]);
		M = max(M, (int)pq2[a[i]].size());
		S.insert(a[i]);
	}
	ll L = 1, num = 0;
	while (L <= M) {
		for(int i: S) {
			ll n = pq2[i].top();
			pq2[i].pop();
			if (pq.size() < K) {
				pq.push(n);
				num += n;
			}
			else if (pq.size() == K && pq.top() > n) {
				num -= pq.top();
				pq.pop();
				num += n;
				pq.push(n);
			}
			if (pq2[i].size())
				S2.insert(i);
		}
		if (pq.size() < K)
			ans[L] = -1;
		else
			ans[L] = num;
		L++;
		S = S2;
		S2.clear();
	}
	for (int i = 1; i <= N; i++) {
		if (i >= M)
			cout << ans[M] << " ";
		else
			cout << ans[i] << " ";
	}
}