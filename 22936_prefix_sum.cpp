// 210822 #22936 주간달력 Gold IV
// prefix_sum, bruth-force
// O(NM)
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 50801;
int N, M, p[MAX], T, pp[MAX], d[MAX];
vector<pi> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	T = 7 * N;
	v.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i].first >> v[i].second;
		pp[v[i].first]++;
		pp[v[i].second + 1]--;
	}
	for (int i = 1; i < MAX; i++) {
		p[i] = p[i - 1] + pp[i];
		d[i] = d[i - 1] + p[i];
	}
	int ans = 0, idx = -1;
	for (int i = T; i < MAX; i++) {
		if (ans < d[i] - d[i - T]) {
			ans = d[i] - d[i - T];
			idx = i - T + 1;
		}
	}
	int res = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			if (v[i].second >= idx + 7 * j &&
				v[i].first <= idx + 7 * (j + 1) - 1)
				res++;
		}
	}
	cout << res << "\n";
}