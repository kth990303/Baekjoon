// 200907 #1613 ���� Gold III
// dfs�� bfs�� �ϸ� TLE O(SV^2)=50000 * 400^2
// �ѹ��� ���̽��� ���� Floyd���� ������, �� ���� 5������ ���̽�
// floyd�� O(V^3)�̳� �� ���� V�� ����+�����̵�������� ���� ���� �޸�
// �Դٰ� ��� ���İ��� �����⿡ ���� (because of �������迭~)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 401;
const int INF = 1000000007;
int N, K, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!d[i][j])
				d[i][j] = INF;
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if (d[a][b] == INF && d[b][a] == INF)
			cout << "0\n";
		else if (d[a][b] == INF)
			cout << "1\n";
		else
			cout << "-1\n";
	}
}