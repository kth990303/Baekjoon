// 200824 #14621 ���� �ȵǴ� ���� Gold IV
// ���ڸ��� MST�� �������� ����
// ����������� �����ȵǴ� ����~
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
		// ������ �ٸ��� �ƿ� ��� ���ϰ�
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
	// ���Ͽ� ���ε� ����, ���� �ͼ�������
	// �� �κ� ���� ������ �������� mst
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