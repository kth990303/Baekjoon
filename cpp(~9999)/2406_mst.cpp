// 200921 #2406 안정적인 네트워크 Gold III
// MST인데, 1번 빼고 MST를 이뤄야됨
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
vector<pair<int, pair<int, int>>> v;
int N, M, ans, a[MAX], p[MAX];
vector<pair<int, int>> res;
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

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;
			if (i == j)
				continue;
			v.push_back({ cost, {i, j} });
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		int cost = v[i].first;
		// 1번일 경우 연결할 필요가 없음.
		if (node1 == 1 || node2 == 1)
			continue;
		if (merge(node1, node2)) {
			ans += cost;
			// 연결한 쌍을 출력하기 위해 따로 배열에 저장
			res.push_back({ node1, node2 });
		}
	}
	cout << ans << " " << res.size() << "\n";
	for (auto i : res) {
		cout << i.first << " " << i.second << "\n";
	}
}