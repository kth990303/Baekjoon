// 210819 #6091 핑크플로이드 Platinum V
// complete-graph => tree : MST
// can proof mathematical induction
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 1025;
int N, a[MAX][MAX], p[MAX*MAX];
vector<pair<int, pi>> v;
vector<int> c[MAX];
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
	if (a > b) swap(a, b);
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j)
				continue;
			cin >> a[i][j];
			a[j][i] = a[i][j];
			v.push_back({ a[i][j], {i, j} });
		}
	}
	sort(all(v));
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		int cost = v[i].first;
		if (find(n1) != find(n2)) {
			cnt++;
			merge(n1, n2);
			c[n1].push_back(n2);
			c[n2].push_back(n1);
		}
		if (cnt == N - 1)
			break;
	}
	for (int i = 0; i < N; i++) {
		sort(all(c[i]));
		cout << c[i].size() << " ";
		for (auto j : c[i])
			cout << j + 1 << " ";
		cout << "\n";
	}
}