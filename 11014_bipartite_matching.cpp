// 211017 #11014 да╢в2 Platinum II
// Bipartite Matching = Minimum Vertex Cover = Maximum Independent Set
// O(Esqrt(V))
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
const int MAX = 83;
const int INF = 0x3f3f3f3f;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, d[MAX*MAX];
char a[MAX][MAX];
vector<int> v[MAX*MAX];
bool used[MAX * MAX], able[MAX * MAX];
bool dfs(int cur) {
	for (auto i : v[cur]) {
		if (used[i])
			continue;
		used[i] = true;
		if (d[i] == -1 || dfs(d[i])) {
			d[i] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < MAX * MAX; i++) {
			v[i].clear();
			able[i] = false;
			d[i] = -1;
		}
		cin >> N >> M;
		int ans = N * M, res = 0;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < M; j++) {
				a[i][j] = s[j];
				if (a[i][j] == 'x')
					ans--;
				else
					able[i*M+j] = true;
			}
		}
		for (int j = 0; j < M; j+=2) {
			for (int i = 0; i < N; i++) {
				int cur = i * M + j;
				if (able[cur]) {
					int left = cur - 1;
					int right = cur + 1;
					int downLeft = left + M;
					int downRight = right + M;
					int upLeft = left - M;
					int upRight = right - M;
					if (j && able[left])
						v[cur].push_back(left);
					if (j != M - 1 && able[right])
						v[cur].push_back(right);
					if (i != N - 1 && j && able[downLeft])
						v[cur].push_back(downLeft);
					if (i != N - 1 && j != M - 1 && able[downRight])
						v[cur].push_back(downRight);
					if (i && j && able[upLeft])
						v[cur].push_back(upLeft);
					if (i && j != M - 1 && able[upRight])
						v[cur].push_back(upRight);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int cur = i * M + j;
				fill(used, used + MAX * MAX, false);
				if (dfs(cur))
					res++;
			}
		}
		cout << ans - res << "\n";
	}
}