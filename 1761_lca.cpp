// 200822 �ּ� ���� ���� #1761 Platinum V
// kks227�� ��α׷� ������ ����
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// MAX ���� �ø�����!
const int MAX = 16;	// 2^16=65536
int p[40001][MAX + 1];	// �θ� �迭 (i�� 2^j��° ���� �迭)
vector<pair<int, int>> v[40001];
int d[40001];	// ���� �迭
int len[40001];	// �Ÿ� �迭
int N, M;
// �Ÿ�, ���� �ʱ�ȭ �� �������� ���� �ʱ�ȭ
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.first] == -1) {
			len[i.first] = len[cur] + i.second;
			d[i.first] = d[cur] + 1;
			p[i.first][0] = cur;
			init(i.first);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b, cost });
		v[b].push_back({ a,cost });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + N+1, -1);
	d[1] = 0;
	// initialize tree
	init(1);
	// initialize all parent info
	for (int j = 0; j < MAX; j++) {
		for (int i = 2; i <= N; i++) {
			int tmp = p[i][j];
			if (tmp != -1) {
				p[i][j + 1] = p[tmp][j];
			}
		}
	}
	// query
	cin >> M;
	while (M--) {
		int a, b, ans = 0;
		cin >> a >> b;
		int lenA = len[a];
		int lenB = len[b];
		if (d[a] < d[b]) swap(a, b);
		int diff = d[a] - d[b];

		int j = 0;
		while (diff) {
			// O(lgN)
			if (diff % 2) {
				a = p[a][j];
			}
			diff /= 2;
			j++;
		}
		// �ٸ� ��� ������ ã�Ƽ�
		if (a != b) {
			for (int j = MAX; j >= 0; j--) {
				// �������� ������ ����
				if (p[a][j] != -1 && p[a][j] != p[b][j]) {
					a = p[a][j];
					b = p[b][j];
				}
			}
			// ������������ �ø���
			a = p[a][0];
		}
		int lenLCA = len[a];
		cout << lenA + lenB - 2 * lenLCA << "\n";
	}
}