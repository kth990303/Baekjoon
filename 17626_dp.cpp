// 201213 #17626 Four Squares Silver V
// DP: Silver II / Bruth-force: Silver V
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 50001;
const int INF = 1e9 + 7;
int N, d[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(d, d + N + 1, INF);
	for (int i = 1; i * i < MAX; i++) {
		d[i * i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j < i; j++) {
			// �ᱹ�� � �������� ���� ���¿��� �̷�����׹Ƿ�.
			// ó���� d[i-j]+d[j]�� �ߴٰ� Ʋ��.
			d[i] = min(d[i], d[i - j * j] + d[j * j]);
		}
	}
	cout << d[N] << "\n";
}