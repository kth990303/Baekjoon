// 200829 #3176 ���� ��Ʈ��ũ Platinum IV
// ���� ������ �� ���ϴ°� �ƴ϶� ���� ª�� �� ���
// ���̸� MST ���� �ߴ��ϸ�,,, �Ф� -> LCA�� ����~
// ª����, ��ű��� �ð� ����ؼ� �迭 �߰��� ������
// �׿ܿ� LCA�� ����� ��~
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
const int INF = 1000000007;
const int MAX = 100001;
const int SIZE = 17;	// 2^16=65536
using namespace std;
int p[MAX][SIZE + 1];
int d[MAX];
int l[MAX][SIZE + 1];	// ���� �� ��
int s[MAX][SIZE + 1];	// ���� ª�� ��
vector<pair<int, int>> v[MAX];
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.second] == -1) {
			d[i.second] = d[cur] + 1;
			p[i.second][0] = cur;

			l[i.second][0] = i.first;
			s[i.second][0] = i.first;
			init(i.second);
		}
	}
}
int N, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j <= SIZE; j++) {
			s[i][j] = INF;
			l[i][j] = -1;
		}
	}
	d[1] = 0;
	init(1);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 2; i <= N; i++) {
			int tmp = p[i][j];
			if (tmp != -1) {
				p[i][j + 1] = p[tmp][j];
				s[i][j + 1] = min(s[i][j], s[tmp][j]);
				l[i][j + 1] = max(l[i][j], l[tmp][j]);
			}
		}
	}
	cin >> K;
	while (K--) {
		int ans1, ans2;	// short, long
		ans1 = INF;
		ans2 = -1;
		int a, b;
		cin >> a >> b;
		if (d[a] < d[b])
			swap(a, b);
		int diff = d[a] - d[b];

		int j = 0;
		while (diff) {
			if (diff % 2) {
				ans1 = min(ans1, s[a][j]);
				ans2 = max(ans2, l[a][j]);
				// ���� ���� �ٲ�
				// �ȹٲٸ� ���� ����° ���� �̻��Ұ���
				// ���� �ٲٸ� �ڽ� ���� ������ ���� �ȵ�
				a = p[a][j];
			}
			diff /= 2;
			j++;
		}
		if (a != b) {
			for (int i = SIZE; i >= 0; i--) {
				if (p[a][i] != -1 && p[a][i] != p[b][i]) {
					ans1 = min(ans1, min(s[a][i], s[b][i]));
					ans2 = max(ans2, max(l[a][i], l[b][i]));
					// �̰͵� ����... ans����!
					a = p[a][i];
					b = p[b][i];
				}
			}
			ans1 = min(ans1, min(s[a][0], s[b][0]));
			ans2 = max(ans2, max(l[a][0], l[b][0]));
		}
		cout << ans1 << " " << ans2 << "\n";
	}
}