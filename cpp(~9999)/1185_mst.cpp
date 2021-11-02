// 201224 #1185 유럽여행 Platinum IV
// MST + greedy
// O(PlgP)
// N-1개의 길만 존재하며, 어차피 왔던 길로 다시 되돌아와야됨.
// 출발점 또한 비용에 포함됨.
#include <iostream>
#include <vector>
#include <algorithm>
const int MAX = 10001;
using namespace std;
int N, M, p[MAX], ans;
vector<pair<int, pair<int, int>>> v;
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

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	vector<int> place;
	int start = 1000;
	place.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> place[i];
		start = min(start, place[i]);
	}
	// 출발점을 비용에 포함.
	// 출발점은 간선을 통해 비용이 추가되지 않는 케이스이므로 이렇게.
	// 가장 최소비용을 출발점으로 잡는 이유
	// 어차피, 모든 길을 다 들리는거, 출발점이라도 가장 작게
	ans += start;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// 어차피 왕복하면, b->a (a비용) + a->b (b비용) + 간선*2
		v.push_back({ cost * 2 + place[a] + place[b], {a,b} });
		v.push_back({ cost * 2 + place[a] + place[b], {b,a} });
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		// 다리가 N-1개면 break해주자
		if (cnt == N - 1)
			break;
		int cost = v[i].first;
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		if (merge(node1, node2)) {
			ans += cost;
			cnt++;
		}
	}
	cout << ans << "\n";
}