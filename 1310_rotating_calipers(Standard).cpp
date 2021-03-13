// 210313 #1310 달리기 코스 Platinum IV
// rotating_calipers(Standard)
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 100001;
int N;
struct Point {
	ll x, y, p, q;
	Point() {}
	Point(ll x1, ll y1, ll p1 = 0, ll q1 = 0)
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
ll ccw(const Point& p1, const Point& p2, const Point& p3) {
	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}
ll dist(const Point& p1, const Point& p2) {
	return (p2.x - p1.x) * (p2.x - p1.x)
		+ (p2.y - p1.y) * (p2.y - p1.y);
}
Point operator-(const Point& p1, const Point& p2) {
	return Point(p1.x - p2.x, p1.y - p2.y);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i].x >> a[i].y;
	}
	swap(a[0], *min_element(a, a + N));
	for (int i = 1; i < N; i++) {
		a[i].p = a[i].x - a[0].x;
		a[i].q = a[i].y - a[0].y;
	}
	sort(a + 1, a + N);
	stack<int> S;
	S.push(0);
	S.push(1);
	for (int i = 2; i < N; i++) {
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
	ll ans = dist(a[left], a[right]);
	pair<int, int> ret1, ret2;
	ret1 = { hull[left].x, hull[left].y };
	ret2 = { hull[right].x, hull[right].y };
	for (int i = 0; i < hull.size(); i++) {
		Point p1 = hull[(left + 1) % hull.size()] - hull[left];
		Point p2 = hull[right] - hull[(right + 1) % hull.size()];
		if (ccw({ 0,0 }, p1, p2) <= 0) {
			left = (left + 1) % hull.size();
		}
		else {
			right = (right + 1) % hull.size();
		}
		if (ans < dist(hull[left], hull[right])) {
			ans = dist(hull[left], hull[right]);
			ret1 = { hull[left].x, hull[left].y };
			ret2 = { hull[right].x, hull[right].y };
		}
	}
	cout << ans << "\n";
}