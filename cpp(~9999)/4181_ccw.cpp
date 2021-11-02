// 210319 #4181 Convex Hull Platinum IV
// convex hull + linear line exception...
// ccw sorting
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 100001;
const int INF = 1e9 + 7;
int C, minX = INF, minY = INF, cnt;
struct Point {
	ll x, y, p, q;
	Point() {}
	Point(ll x1, ll y1, ll p1 = 0, ll q1 = 0)
		:x(x1), y(y1), p(p1), q(p1) {}
	bool operator<(const Point& O) {
		if (q * O.p != p * O.q)
			return q * O.p < p* O.q;
		if (x != O.x)
			return x < O.x;
		return y < O.y;
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

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> C;
	for (int i = 0; i < C; i++) {
		ll x, y;
		char ch;
		cin >> x >> y >> ch;
		if (ch == 'N')
			continue;
		a[cnt++] = { x, y };
	}
	swap(a[0], *min_element(a, a + cnt));
	cout << cnt << "\n";
	for (int i = 1; i < cnt; i++) {
		a[i].p = a[i].x - a[0].x;
		a[i].q = a[i].y - a[0].y;
	}
	sort(a + 1, a + cnt);
	// last linear line exception
	int idx = -1;
	for (int i = cnt - 1; i >= 0; i--) {
		if (ccw(a[(i + 1) % cnt], a[i], a[i - 1])) {
			idx = i;
			break;
		}
	}
	reverse(a + idx, a + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << a[i].x << " " << a[i].y << "\n";
	}
}