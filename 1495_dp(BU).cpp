// 200921 #1495 기타리스트 Silver I
// 바텀업 방식
// O(NM)인데, N, M 범위가 적어서 탑다운이랑 큰 차이는 안남
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