// 200815 ���� 1504 �ּ�Ǯ�� <���ͽ�Ʈ��> ���4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;
vector<pair<int, int>> v[801];
int N, E;
int dijkstra(int s, int e) {
	// ������, ���� ���� ���
	if (s == e)
		return 0;
	// ��� �ʱ�ȭ
	int d[801] = { 0 };
	// �ּҺ���� ���ϹǷ� ó�� ���� INF
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	// ����� �켱������ �ϴ� ť ����
	// priority_queue<T, vector<T>, greater<T>> pq; �� ����
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	// ó�� ����� 0���ݾ�~
	d[0] = 0;
	// bfsó�� �غ���~
	// pq �� ������ �ϸ� ��� ��� ����� �ִܰ�� ������
	while (!pq.empty()) {
		int cur = pq.top().second;
		// ����� �ּ��� ���� �ϹǷ� ������
		// ������ ���ͽ�Ʈ��� ����� ���� �����ϴϱ�
		// �� ������ �ؿ�~
		int cost = -pq.top().first;
		pq.pop();
		// ������ ���� �ȵǴ� ����
		// cost���� ���� ���� ������ ����Ÿ��� �Ǵϱ� �� if�� ��������
		// ����: �븸 ���� ����~ (������� �Ф̤� 200815)
		if (d[cur] < cost)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			// s�� ������ִ� ������ ��������
			int next = v[cur][i].first;
			// ������� ���+���� ���
			int nCost = v[cur][i].second + cost;
			if (nCost < d[next]) {
				// ��� �ּ��� ���
				// ��, ó���� INF���״� ù������ ��� ������ ������.
				d[next] = nCost;
				// ���� pq�� �־��
				pq.push({ -nCost, next });
			}
		}
	}
	return d[e];
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int s1, s2;
	cin >> s1 >> s2;
	// ��... �� ���̶� ���� �����̴٤���
	int a1 = dijkstra(1, s1) + dijkstra(s1, s2) + dijkstra(s2, N);
	int a2 = dijkstra(1, s2) + dijkstra(s2, s1) + dijkstra(s1, N);
	int ans = min(a1, a2);
	// INF ��ó�� ��� ��ΰ� ���� ��찡 �־��ٴ� �Ŵϱ�
	if (ans >= 200000 * N || ans <= 0)
		cout << -1;
	else
		cout << ans;
}