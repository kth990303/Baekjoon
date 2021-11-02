// 201224 #1185 �������� Platinum IV
// MST + greedy
// O(PlgP)
// N-1���� �游 �����ϸ�, ������ �Դ� ��� �ٽ� �ǵ��ƿ;ߵ�.
// ����� ���� ��뿡 ���Ե�.
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
	// ������� ��뿡 ����.
	// ������� ������ ���� ����� �߰����� �ʴ� ���̽��̹Ƿ� �̷���.
	// ���� �ּҺ���� ��������� ��� ����
	// ������, ��� ���� �� �鸮�°�, ������̶� ���� �۰�
	ans += start;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// ������ �պ��ϸ�, b->a (a���) + a->b (b���) + ����*2
		v.push_back({ cost * 2 + place[a] + place[b], {a,b} });
		v.push_back({ cost * 2 + place[a] + place[b], {b,a} });
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		// �ٸ��� N-1���� break������
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