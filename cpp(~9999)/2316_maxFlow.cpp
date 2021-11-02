// 200828 #2316 ���� �պ��ϱ�2 Platinum III
// kks227�� ��α� ���: ���� �п�
// ó���� visit���� �����ߴٰ�
// visit���� �����ϸ� ������ �÷ο� �� ������ ����
// 1, 2���� ����! �п��� ��, � �� �� �̾����� ����!
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
const int MAX = 802;
const int INF = 1000000007;
using namespace std;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> v[MAX];
int N, P, ans;
// �� �κ��� �������� ��Ʈ��ũ �÷ο�
void maxFlow(int s, int e) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto i : v[x]) {
				if (c[x][i] - f[x][i] > 0 && d[i] == -1) {
					q.push(i);
					d[i] = x;
					if (i == e)
						break;
				}
			}
		}
		if (d[e] == -1)
			break;
		int flow = INF;
		for (int i = e; i != s; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for (int i = e; i != s; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		ans += flow;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> P;
	// 1, 2�� ���� ������ �ѹ��� ����
	// 3��: 5->6 4��: 7->8,...
	for (int i = 3; i <= N; i++) {
		c[i * 2 - 1][i * 2] = 1;

		v[i * 2 - 1].push_back(i * 2);
		v[i * 2].push_back(i * 2 - 1);
	}
	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		
		c[a * 2][b * 2 - 1] = 1;
		c[b * 2][a * 2 - 1] = 1;	// ������ �뷮

		v[a * 2].push_back(b * 2 - 1);
		v[b * 2 - 1].push_back(a * 2);	// ��
		v[b * 2].push_back(a * 2 - 1);
		v[a * 2 - 1].push_back(b * 2);	// ��
	}
	// 1���� ������ -> 2���� ��������
	maxFlow(2,3);
	cout << ans;
}
