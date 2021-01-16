// 210116 #1043 °ÅÁþ¸» Gold IV
// Union-find
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 51;
int N, M, a[MAX], p[MAX], ans;
vector<int> v[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return a = find(p[a]);
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

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	int n, m, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p[num] = 0;	// know the truth
	}
	// truth: 0, don't know: i
	for (int i = 0; i < M; i++) {
		cin >> m >> k;
		// At least one person attends the party
		v[i].push_back(k);
		for (int j = 1; j < m; j++) {
			int num;
			cin >> num;
			merge(k, num);
			// party members
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = 0; j < v[i].size(); j++) {
			// if don't know the truth(not 0)
			if (find(v[i][j]))
				cnt++;
		}
		// All they don't know the truth ? ans++ : ans
		if (cnt == v[i].size())
			ans++;
	}
	cout << ans << "\n";
}