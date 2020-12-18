// 201218 #13424 ��и��� Gold V
// 0x3f�� int�� 63... memset(��Ʈ)�̶� int�� ���̳��ٴ� �� ����...!!!
// N�� �۾Ƽ� O(N^3) Ǯ���� �÷��̵嵵 ����.
// ���ͽ�Ʈ�� ������ �����⺸�� �̰� �� ����. �������� ������!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
const int INF = 0x3f;
const int MAX = 101;
using namespace std;
int N, M, K, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		memset(d, INF, sizeof(d));
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			d[i][i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			cin >> a >> b >> cost;
			d[a][b] = cost;
			d[b][a] = cost;
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					d[i][j] = min({d[i][j], d[i][k] + d[k][j]});
				}
			}
		}
		cin >> K;
		vector<int> start;
		start.resize(K);
		for (int i = 0; i < K; i++) {
			cin >> start[i];
		}
		// int ans=INF�� �ߴٰ� �¿�Ʋ...������
		int ans = 1e9 + 7, idx = 0;
		for (int i = 1; i <= N; i++) {
			int dis = 0;
			for (auto j: start) {
				dis += d[j][i];
			}
			if (ans > dis) {
				idx = i;
				ans = dis;
			}
		}
		cout << idx << "\n";
	}
}