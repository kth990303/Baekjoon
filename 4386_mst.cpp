// 200904 #4386 별자리 만들기 Gold IV
// Kruskal을 이용한 mst 만들기
// 이차원 배열을 유니온파인드 해야되는줄...식겁했는데 다행
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 101;
int N, p[MAX];
vector <pair<double, pair<int, int>>> v;
struct Star {
	double x, y;
};
Star star[MAX];
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
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> star[i].x >> star[i].y;
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double _x = star[i].x - star[j].x;
			double _y = star[i].y - star[j].y;
			double d = sqrt(_x * _x + _y * _y);
			v.push_back({ d,{i, j} });
		}
	}
	sort(v.begin(), v.end());
	double ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		double cost = v[i].first;
		if (merge(node1, node2)) {
			ans += cost;
		}
	}
	cout << ans << "\n";
}