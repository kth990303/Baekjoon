// 200921 #4343 Arctic Network Gold III
// 현재는 골드2나 골드3로 내려갈 각임
// 전형적인 mst. 왜 골2..?
// 테스트케이스가 여러개므로 초기화해줘야됨.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 25001;
vector<pair<double, pair<int, int>>> v;
struct Place {
	double x, y;
};
Place place[MAX];
double a[MAX], N, M;
int p[MAX];
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

	cout << fixed;
	cout.precision(2);

	int t;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			p[i] = i;
		}
		for (int i = 1; i <= M; i++) {
			double x, y;
			cin >> place[i].x >> place[i].y;
		}
		for (int i = 1; i <= M; i++) {
			for (int j = i + 1; j <= M; j++) {
				double d1 = (place[i].x - place[j].x);
				double d2 = (place[i].y - place[j].y);
				double dis = sqrt(d1 * d1 + d2 * d2);
				v.push_back({ dis, {i, j} });
			}
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int node1 = v[i].second.first;
			int node2 = v[i].second.second;
			double cost = v[i].first;
			if (merge(node1, node2)) {
				if (++cnt == M - N) {
					cout << cost << "\n";
					break;
				}
			}
		}
	}
}