// 211107 #1025 Á¦°ö¼öÃ£±â Gold V
// bruteforce, implementation
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
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
const int MAX = 11;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, ans = -1;
char a[MAX][MAX];
bool check(int n) {
	int k = sqrt(n);
	if (k * k == n) return true;
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
			if (check(s[j] - '0'))
				ans = max(ans, s[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!i && !j) continue;
			for (int sy = 0; sy < N; sy++) {
				for (int sx = 0; sx < M; sx++) {
					string s;
					int y = sy, x = sx;
					while (1) {
						if (x >= M || y >= N) break;
						s += a[y][x];
						y += i; x += j;
						if (check(stoi(s)))
							ans = max(ans, stoi(s));
					}
					s = "";
					y = sy, x = sx;
					while (1) {
						if (x < 0 || y >= N) break;
						s += a[y][x];
						y += i; x -= j;
						if (check(stoi(s)))
							ans = max(ans, stoi(s));
					}
					s = "";
					y = sy, x = sx;
					while (1) {
						if (x >= M || y < 0) break;
						s += a[y][x];
						y -= i; x += j;
						if (check(stoi(s)))
							ans = max(ans, stoi(s));
					}
					s = "";
					y = sy, x = sx;
					while (1) {
						if (x < 0 || y < 0) break;
						s += a[y][x];
						y -= i; x -= j;
						if (check(stoi(s)))
							ans = max(ans, stoi(s));
					}
				}
			}
		}
	}
	cout << ans << "\n";
}