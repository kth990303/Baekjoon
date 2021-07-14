// 210714 #22116 창영이와퇴근 Gold IV
// MST O(N^2lg(N^2))
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pi;
const int MAX = 1001;
int N, a[MAX][MAX], p[MAX * MAX], ans;
vector<pair<int, pi>> v;
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
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			p[i * N + j] = i * N + j;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n1 = i * N + j;
			if (i + 1 < N) {
				int cost = abs(a[i+1][j] - a[i][j]);
				int n2 = (i + 1) * N + j;
				v.push_back({ cost, {n1, n2} });
			}
			if (j + 1 < N) {
				int cost = abs(a[i][j + 1] - a[i][j]);
				int n2 = i * N + j + 1;
				v.push_back({ cost, {n1, n2} });
			}
		}
	}
	sort(all(v));
	for (int i = 0; i < v.size(); i++) {
		if (find(0) == find(N * N - 1))
			break;
		int cost = v[i].first;
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		merge(n1, n2);
		ans = max(ans, cost);
	}
	cout << ans << "\n";
}