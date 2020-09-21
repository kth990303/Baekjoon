// 200921 #1495 ��Ÿ����Ʈ Silver I
// ���Ҿ� ���
// O(NM)�ε�, N, M ������ ��� ž�ٿ��̶� ū ���̴� �ȳ�
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000007;
const int MAX = 101;
int a[MAX];
bool d[MAX][1001];
int N, S, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	d[0][S] = true;
	int v = S;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if (!d[i][j])
				continue;
			if (j - a[i] >= 0)
				d[i + 1][j - a[i]] = true;
			if (j + a[i] <= M)
				d[i + 1][j + a[i]] = true;
		}
	}
	int ans = -1;
	for (int i = 0; i <= M; i++) {
		if (d[N][i])
			ans = i;
	}
	cout << ans << "\n";
}