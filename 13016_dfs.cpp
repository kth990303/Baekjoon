// 210608 #13016 ³» ¿Þ¼Õ¿¡´Â Èæ¿°·æÀÌ Àáµé¾î ÀÖ´Ù Platinum V
// dfs +tree's diameter
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 50001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, d[MAX], d2[MAX], A, B, tmp;
vector<pi> v[MAX];
bool visit[MAX];
void dfsA(int cur, int cost) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.second]) {
			dfsA(i.second, cost + i.first);
		}
	}
	if (tmp < cost) {
		tmp = cost;
		A = cur;
	}
}
void dfsB(int cur, int cost) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.second]) {
			dfsB(i.second, cost + i.first);
		}
	}
	if (tmp < cost) {
		tmp = cost;
		B = cur;
	}
	d[cur] = cost;
}
void dfs(int cur, int cost) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.second]) {
			dfs(i.second, cost + i.first);
		}
	}
	d2[cur] = cost;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	dfsA(1, 0);
	fill(visit, visit + MAX, false);
	tmp = 0;
	dfsB(A, 0);
	fill(visit, visit + MAX, false);
	dfs(B, 0);
	for (int i = 1; i <= N; i++) {
		cout << max(d[i], d2[i]) << "\n";
	}
}