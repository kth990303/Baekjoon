// 200919 #11048 이동하기 Silver I
// 바텀업 방식
// O(NM)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int a[MAX][MAX], d[MAX][MAX], N, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// max 중첩보다 8ms 빠름
			d[i][j] = max({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] });
			d[i][j] += a[i][j];
		}
	}
	cout << d[N][M] << "\n";
}}