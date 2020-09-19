// 200919 #11060 점프 점프 Silver II
// O(N^2)
// 개인적으로 이 문제는 탑다운이 훨씬 쉬운듯
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
const int INF = 1000000007;
int N, a[MAX], d[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(d, d + N, -1);
	d[0] = 0;
	for (int i = 0; i < N - 1; i++) {
		// -1일 경우 갈 수 없는 칸
		if (d[i] == -1)
			continue;
		for (int j = 1; j <= a[i]; j++) {
			// 범위 체크
			if (i + j < N) {
				// 아직 방문하지 않은 곳이면
				if (d[i + j] == -1)
					d[i + j] = d[i] + 1;
				// 이미 방문한 곳이면 더 짧은 거리로
				else
					d[i + j] = min(d[i + j], d[i] + 1);
			}
		}
	}
	cout << d[N - 1];
}