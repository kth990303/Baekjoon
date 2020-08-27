// 200827 #6086 �ִ� ���� Platinum IV
// �ִ����� ���� (�̺и�Ī�� ����) ����
// ������ ��α�, ���� ��α� ����
// ���� ������ ���� �ʿ��ϴ�
// O(VE^2)
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int MAX = 53;	// ���ĺ� A~Z, a~z
const int INF = 1000000007;
using namespace std;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> v[MAX];
int N, ans;
int ctoi(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	return c - 'A';
}
void maxFlow(int s, int e) {
	while (1) {
		// �湮���� ���� ������ -1�� �ʱ�ȭ
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(s);
		// bfs�� ��� Ž��
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			// ������ �����������
			for (auto y : v[x]) {
				// ������ �뷮�� �� ���� �ʾ� ������ �ִ���
				// ���� �湮���� ���� �� �߿���
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;	// ��� ���
					if (y == e)	// �������̸� Ż��
						break;
				}
			}
		}
		// ������ ��� ���� ��� Ż��
		if (d[e] == -1)
			break;
		int flow = INF;
		for (int i = e; i != s; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// ���� ���� ������ŭ ������ �����
		for (int i = e; i != s; i = d[i]) {
			f[d[i]][i] += flow;	// �������� ������
			f[i][d[i]] -= flow;	// ���粨���� ���ְ�
		}
		// ������ �����༭ ������ �̵溻�� �߰�����
		ans += flow;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b;
		int w;
		cin >> a >> b >> w;
		a = ctoi(a);
		b = ctoi(b);
		v[a].push_back(b);
		v[b].push_back(a);
		// ���� ������ ������ ���� �� ����!
		// + �Ⱥٿ��ָ� Ʋ��...
		c[a][b] += w;
		// ������̴ϱ� �̰� �����൵ Ʋ��...
		c[b][a] += w;
	}
	maxFlow(ctoi('A'), ctoi('Z'));
	cout << ans << "\n";
}