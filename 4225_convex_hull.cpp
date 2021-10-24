// 211024 #4225 ¾²·¹±â½´Æ® Platinum III
// convex_hull
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 103;
const double INF = 0x3f3f3f3f;
const double EPS = 1e-12;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int t, N;
struct Point {
	double x, y, p, q;
	Point() {}
	Point(double x1, double y1, double p1 = 0, double q1 = 0)
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
double ccw(const Point& p1, const Point& p2, const Point& p3) {
	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> N && N) {
		double ans = INF;
		for (int i = 0; i < N; i++) {
			// lots of test case, necessary init
			a[i] = { 0,0,0,0 };
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
		for (int i = 0; i < hull.size(); i++) {
			hull[i] = a[S.top()];
			S.pop();
		}
		int n = hull.size();
		for (int i = 0; i < n; i++) {
			double A, B, C, res = 0;
			if (hull[i].x == hull[(i + 1) % n].x) {
				for (int j = 0; j < n; j++) {
					res = max(res, abs(hull[i].x - hull[j].x));
				}
				ans = min(ans, res);
				continue;
			}
			A = (hull[(i + 1) % n].y - hull[i].y) / (hull[(i + 1) % n].x - hull[i].x);
			B = -1;
			C = hull[i].y - A * hull[i].x;
			for (int j = 0; j < n; j++) {
				res = max(res, abs(A * hull[j].x + B * hull[j].y + C)
					/ sqrt(A * A + B * B));
			}
			ans = min(ans, res);
		}
		cout << fixed;
		cout.precision(2);
		cout << "Case " << ++t << ": " << ans + 0.00499999 << "\n";
	}
}