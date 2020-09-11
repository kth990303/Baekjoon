// 200912 #16482 한 점에서 만나라! Platinum III
// 체바의 정리를 쓰면 끝나는 문제
// 플로우컵에서 제2cos법칙, 오일러 정리를 너무 좋아하는 것 같다
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c, d, e;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(10);

	cin >> a >> b >> c >> d >> e;
	double ans = (c - d) * (a - e) * b / ((c - d) * (a - e) + d * e);
	cout << ans << "\n";
}