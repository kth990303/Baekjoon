// 200817 MST 이용하는 문제 1774 골4
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//# 1774 추가예제
//5 2
//1 1
//3 1
//5 3
//3 7
//1 4
//2 3
//1 3
//output: 6.61
using namespace std;
typedef long long ll;
typedef long double ld;
int N, M;
int p[1001];
pair<double, double> god[1001];
vector<pair<double, pair<int, int>>> v;
// disjoint set
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	ld ans = 0;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		p[i] = i;
	}
	// 우주신 좌표 설정
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		god[i] = { x, y };
	}
	// 먼저 연결해놓기
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a - 1, b - 1);
		cnt++;	// N-1-cnt개만큼 더 간선 연결 가능
	}
	// 거리가 짧은 순으로 sort하자
	// 어차피 시간복잡도: 1000*1000
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			double d = sqrt((god[i].first - god[j].first) * (god[i].first - god[j].first)
				+ (god[i].second - god[j].second) * (god[i].second - god[j].second));
			v.push_back({ d, {i, j} });
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		double d = v[i].first;
		if (merge(node1, node2)) {
			ans += d;
			if (++cnt == N - 1)
				break;
		}
	}

	printf("%.2Lf", ans);
}