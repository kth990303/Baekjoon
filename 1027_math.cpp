// 210131 #1027 °íÃþ °Ç¹° Gold IV
// geometry : Slope of a straight line
// Attention data type! (double)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 51;
int N, ans;
pair<int, int> p[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		p[i].first = i;
		cin >> p[i].second;
	}
	for (int i = 1; i <= N; i++) {
		double x1 = (double)p[i].first;
		double y1 = (double)p[i].second;
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			double x2 = (double)j;
			double y2 = (double)p[j].second;
			double k = (y2 - y1) / (x2 - x1);
			double t = y2 - k * x2;
			bool flag = true;
			for (int l = min(i, j) + 1; l < max(i, j); l++) {
				double y3 = (double)p[l].second;
				if (k * l + t <= y3) {
					flag = false;
					break;
				}
			}
			if (flag)
				cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}