// 210826 #2610 회의준비 Gold II
// union-find + floyd
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
int N, M, d[MAX][MAX], p[MAX];
vector<int> v, c[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (a > b)
		swap(a, b);
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	memset(d, INF, sizeof(d));
	for (int i = 1; i <= N; i++) {
		d[i][i] = 0;
		p[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		d[n1][n2] = d[n2][n1] = 1;
		merge(n1, n2);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		c[find(i)].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		if (!c[i].size())
			continue;
		int ans = INF, idx = -1;
		for (int j = 0; j < c[i].size(); j++) {
			int n1 = c[i][j];
			int ret = 0;
			for (int k = 0; k < c[i].size(); k++) {
				int n2 = c[i][k];
				ret = max(ret, d[n1][n2]);
			}
			if (ret < ans) {
				ans = ret;
				idx = n1;
			}
		}
		v.push_back(idx);
	}
	sort(all(v));
	cout << v.size() << "\n";
	for (auto i : v)
		cout << i << "\n";
}