// 201209 #10159 ���� Gold III
// N�� ũ�⵵ 100���� �۰�, ��� ����� ������ �ľ�->floyd(O(N^3))
// Q. �� topological sort(��������)�δ� �Ұ���?
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 101;
// 0x7f�� �ϴٰ�, �����÷ο찡 �߻��� �� ����.
// 2*INF ����� ���ԵǹǷ�, ���⼱ 0x3f�� ����.
const int INF = 0x3f;
int N, M, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	// ���� ���� ���: cost�� ��������
	// ���⼭��, �쿭�� ���� �� ���� ���
	// �ϴ� �ʱ�ȭ�� ���� INF��
	memset(d, INF, sizeof(d));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// �쿭�� ���� �� ���� ��, ���� ����
		// ���⼭�� d[a][b]=1�� ����.
		d[a][b] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// �ٷ� �̺κ� ������ INF=0x3f
				// ��� ��θ� �ľ��ϴ� floyd �̿�
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int ans = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			// d[i][j], d[j][i]��� �쿭�� ���� �� ����� �信 ����
			else if (d[i][j] >= INF && d[j][i] >= INF)
				ans++;
		}
		cout << ans << "\n";
	}
}