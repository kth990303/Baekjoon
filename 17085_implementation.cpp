// 210627 #17085 십자가 두개놓기 Silver I
// implementation O(N^5~N^6)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 16;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, ans;
char a[MAX][MAX];
bool visit[MAX][MAX];
int solve2(int x, int y) {
	int k = min(N, M);
	int ret = 1;
	for (int i = 1; i < k; i++) {
		if (y - i >= 0 && y + i < N && x - i >= 0 && x + i < M) {
			if (visit[y - i][x] || visit[y + i][x] ||
				visit[y][x - i] || visit[y][x + i])
				break;
			if (a[y - i][x] == '#' && a[y + i][x] == '#'
				&& a[y][x - i] == '#' && a[y][x + i] == '#') {
				ret += 4;
			}
			else
				break;
		}
		else break;
	}
	return ret;
}
int solve(int x, int y) {
	int k = min(N, M);
	int ret = 1;
	visit[y][x] = true;
	for (int k = 0; k < N; k++) {
		for (int l = 0; l < M; l++) {
			int s2 = 0;
			if (!visit[k][l] && a[k][l] == '#') {
				s2 = solve2(l, k);
				ans = max(ans, ret * s2);
			}
		}
	}
	for (int i = 1; i < k; i++) {
		if (y - i >= 0 && y + i < N && x - i >= 0 && x + i < M) {
			if (a[y - i][x] == '#' && a[y + i][x] == '#'
				&& a[y][x - i] == '#' && a[y][x + i] == '#') {
				visit[y - i][x] = visit[y + i][x]
					= visit[y][x - i] = visit[y][x + i] = true;
				ret += 4;
				for (int p = 0; p < N; p++) {
					for (int l = 0; l < M; l++) {
						int s2 = 0;
						if (!visit[p][l] && a[p][l] == '#') {
							s2 = solve2(l, p);
							ans = max(ans, ret * s2);
						}
					}
				}
			}
			else
				break;
		}
		else break;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int s1 = 0;
			memset(visit, false, sizeof(visit));
			if (a[i][j] == '#')
				solve(j, i);
		}
	}
	cout << ans << "\n";
}