// 210210 #2254 °¨¿Á °Ç¼³ Platinum V
// Convex Hull... Shit...
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1001;
ll N, ans;
bool used[MAX];
struct Point {
	// memory order
	int number;
	ll x, y, p, q;
	Point() {}
	Point(int number1, ll x1, ll y1, ll p1 = 0, ll q1 = 0)
		: number(number1), x(x1), y(y1), p(p1), q(q1) {}
	// min(y), counter clock order
	bool operator <(const Point O) {
		if (q * O.p != p * O.q) return q * O.p < p* O.q;
		if (y != O.y) return y < O.y;
		return x < O.x;
	}
};
ll ccw(Point p1, Point p2, Point p3) {
	return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}
Point prison;
vector<Point> a;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> prison.x >> prison.y;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < N; i++) {
		a[i].number = i;
	}
	stack<Point> s;
	ll maxN = N;
	while (N > 2) {
		sort(a.begin(), a.end());
		for (int i = 1; i < N; i++) {
			a[i].p = a[i].x - a[0].x;
			a[i].q = a[i].y - a[0].y;
		}
		// counter clock order
		sort(a.begin() + 1, a.end());
		s.push(a[0]);
		s.push(a[1]);
		// ccw -> convex hull
		for (int i = 2; i < N; i++) {
			while (s.size() >= 2) {
				Point second = s.top();
				s.pop();
				Point first = s.top();
				if (ccw(first, second, a[i]) > 0) {
					s.push(second);
					break;
				}
			}
			s.push(a[i]);
		}
		vector<Point> v;
		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}
		// is this convex hull has prison?
		bool leftturn = false, rightturn = false;
		for (int i = 0; i < v.size(); i++) {
			Point second = v[i % v.size()];
			Point first = v[(i + 1) % v.size()];
			if (ccw(first, second, prison) > 0) {
				leftturn = true;
			}
			else if (ccw(first, second, prison) < 0)
				rightturn = true;
			else {
				leftturn = true;
				rightturn = true;
				break;
			}
		}
		if (leftturn == rightturn)
			break;
		for (int i = 0; i < v.size(); i++) {
			used[v[i].number] = true;
		}
		vector<Point> tmp;
		// if this is real, next turn, don't search this convex hull
		for (int i = 0; i < N; i++) {
			if (used[a[i].number])
				continue;
			tmp.push_back({a[i].number, a[i].x, a[i].y });
		}
		N -= v.size();
		a = tmp;
		ans++;
	}
	cout << ans << "\n";
}