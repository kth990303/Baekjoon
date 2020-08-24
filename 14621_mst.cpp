// 200824 #14621 나만 안되는 연애 Gold IV
// 보자마자 MST가 생각나는 문제
// 볼빨간사춘기 나만안되는 연애~
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[1001];
char gender[1001];
vector<pair<int, pair<int, int>>> v;
int N, M, ans;
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
	for (int i = 1; i <= N; i++)
		cin >> gender[i];
	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// 성별이 다르면 아예 고려 안하게
		if(gender[a]!=gender[b])
			v.push_back({ cost, {a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <v.size(); i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		int dis = v[i].first;
		if (merge(node1, node2)) {
			ans += dis;
		}
	}
	// 유니온 파인드 성질, 이젠 익숙해졌다
	// 이 부분 빼면 나머진 전형적인 mst
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (find(1) != find(i))
			flag = false;
	}
	if (!flag)
		cout << -1;
	else
		cout << ans;
}