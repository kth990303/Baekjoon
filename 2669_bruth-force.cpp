// 210203 #2669 직사각형 네개의 합집합의 면적 구하기 Bronze II
// bruth-force, geometry-sweeping very easy version
#include <iostream>
using namespace std;
const int MAX = 101;
bool a[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				a[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (a[i][j])
				ans++;
		}
	}
	cout << ans << "\n";
}