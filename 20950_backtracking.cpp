// 210501 #20950 미술관 미미 Silver II
// backtracking
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 31;
const int INF = 1e9 + 7;
struct Color {
	int r, g, b;
};
int N, ans = INF;
int R, G, B, sumR, sumG, sumB;
Color c[MAX];
bool visit[MAX];
void solve(int cur, int cnt) {
	if (cnt >= 2)
		ans = min(ans, abs(sumR/cnt - R) + abs(sumG/cnt - G) + abs(sumB/cnt - B));
	for (int i = cur; i < N; i++) {
		if (!visit[i] && cnt <= 6) {
			visit[i] = true;
			sumR += c[i].r;
			sumG += c[i].g;
			sumB += c[i].b;
			// solve(cur+1, cnt+1) -> TLE
			solve(i + 1, cnt + 1);
			visit[i] = false;
			sumR -= c[i].r;
			sumG -= c[i].g;
			sumB -= c[i].b;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c[i].r >> c[i].g >> c[i].b;
	}
	cin >> R >> G >> B;
	solve(0, 0);
	cout << ans << "\n";
}