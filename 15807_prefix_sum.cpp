// 210905 #15807 *ºû*¿µ*¿ì* Platinum V
// prefix_sum
// binary_search or dp[MAX][MAX_V][MAX_V] -> TLE
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 100001;
const int MAX_V = 3001;
int N, P, d[MAX_V][MAX_V], k1[MAX_V*2], k2[MAX_V * 2], s[MAX_V][MAX_V];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		x += 1500; y += 1500;
		s[x][y]++;
	}
	for (int j = 0; j < MAX_V; j++) {
		for (int i = 0; i < MAX_V; i++) {
			if (i == 1510 && j == 1509)
				cout << k1[i + j] << " " << k2[j + MAX_V - i] << "\n";
			if (j)
				d[i][j] = d[i][j - 1] + k1[i + j] + k2[j + MAX_V - i];
			int cnt = s[i][j];
			d[i][j] += cnt;
			k1[i + j] += cnt;
			k2[j + MAX_V - i] += cnt;
		}
	}
	cin >> P;
	for (int i = 0; i < P; i++) {
		int x, y;
		cin >> x >> y;
		x += 1500; y += 1500;
		cout << d[x][y] << "\n";
	}
}