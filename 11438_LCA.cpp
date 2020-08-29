// 200829 #11438 LCA 2 Platinum V
// LCA 2 ����
// LCA�� O(logN)�� ��������
// <cmath> ���ϱ� 0.12ms ������
#include <iostream>
#include <cstring>
#include <vector>
const int MAX = 100001;
const int SIZE = 17;	// ceil(log2(MAX))
using namespace std;
int p[MAX][SIZE + 1];	// Ʈ�� �θ� �迭
vector<int> v[MAX];	// Ʈ�� ����
int N, M, d[MAX];	// Ʈ���� ����(����)
void init(int cur) {
	for (auto i : v[cur]) {
		// ���� ������ ���� �ʾҴٸ�
		if (d[i] == -1) {
			// ���粨���� �Ѵܰ� ���� ����
			d[i] = d[cur] + 1;
			// ���� i�� 2^0��° ���� (ù ��° ����)
			p[i][0] = cur;
			// dfs ����
			init(i);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// �ʱ�ȭ
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[1] = 0;
	init(1);
	// p �迭 �ʱ�ȭ
	for (int j = 0; j < SIZE; j++) {
		for (int i = 2; i <= N; i++) {
			// tmp�� i�� 2^j��° ����
			int tmp = p[i][j];
			if (tmp != -1) {
				// i�� 2^(j+1)��° ������
				// tmp�� 2^j��° ���� (�ŵ����� ����)
				p[i][j + 1] = p[tmp][j];
			}
		}
	}
	// query: a,b�������� ã��
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		// ���� �Ÿ� �켱���� ����
		if (d[a] < d[b]) swap(a, b);
		int diff = d[a] - d[b];

		// O(logN)�� ����
		// a�� b�� �������� ������ ������ �̵�
		int j = 0;
		while (diff) {
			if (diff % 2)
				a = p[a][j];
			diff /= 2;
			j++;
		}
		if (a != b) {
			for (int j = SIZE; j >= 0; j--) {
				// ��Ʈ��庸�� ���� ���� ������ �������� ������ ������
				if (p[a][j] != -1 && p[a][j] != p[b][j]) {
					a = p[a][j];
					b = p[b][j];
				}
			}
			// ���������� �ٷ� ����
			a = p[a][0];
		}
		cout << a << "\n";
	}
}