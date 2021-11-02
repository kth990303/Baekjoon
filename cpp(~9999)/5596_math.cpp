// 201230 #5596 시험 점수 Bronze IV
// github desktop test용 코드
#include <iostream>
#include <algorithm>
using namespace std;
int a[4], b[4], u, v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) {
		cin >> a[i];
		u += a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
		v += b[i];
	}
	cout << max(u, v) << "\n";
}
