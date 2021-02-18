// 210218 #9240 로버트 후드 Platinum IV
// rotating_calipers
// slow code because of long double (~68ms)
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
typedef long double ld;
const int MAX = 100001;
int C;
struct Point {
	ld x, y, p, q;
	Point() {}
	Point(ld x1, ld y1, ld p1 = 0, ld q1 = 0)
		:x(x1), y(y1), p(p1), q(p1) {}
	bool operator<(const Point& O) {
		if (q * O.p != p * O.q)
			return q * O.p < p* O.q;
		if (y != O.y)
			return y < O.y;
		return x < O.x;
	}
};
Point a[MAX];
ld ccw(const Point& p1, const Point& p2, const Point& p3) {
	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}
ld dist(const Point& p1, const Point& p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x)
		+ (p2.y - p1.y) * (p2.y - p1.y));
}
Point operator-(const Point& p1, const Point& p2) {
	return Point(p1.x - p2.x, p1.y - p2.y);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(15);

	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> a[i].x >> a[i].y;
	}
	swap(a[0], *min_element(a, a + C));
	for (int i = 1; i < C; i++) {
		a[i].p = a[i].x - a[0].x;
		a[i].q = a[i].y - a[0].y;
	}
	sort(a + 1, a + C);
	stack<int> S;
	S.push(0);
	S.push(1);
	for (int i = 2; i < C; i++) {
		while (S.size() >= 2) {
			int second = S.top();
			S.pop();
			int first = S.top();
			if (ccw(a[first], a[second], a[i]) > 0) {
				S.push(second);
				break;
			}
		}
		S.push(i);
	}
	vector<Point> hull(S.size());
	int left = 0, right = 0;
	for (int i = 0; i < hull.size(); i++) {
		hull[i] = a[S.top()];
		if (hull[left].x > hull[i].x)
			left = i;
		if (hull[right].x < hull[i].x)
			right = i;
		S.pop();
	}
	ld ans = dist(a[left], a[right]);
	for (int i = 0; i < hull.size(); i++) {
		Point p1 = hull[(left + 1) % hull.size()] - hull[left];
		Point p2 = hull[right] - hull[(right + 1) % hull.size()];
		if (ccw({ 0,0 }, p1, p2) <= 0) {
			left = (left + 1) % hull.size();
		}
		else {
			right = (right + 1) % hull.size();
		}
		ans = max(ans, dist(hull[left], hull[right]));
	}
	cout << ans << "\n";
}