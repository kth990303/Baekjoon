// 211105 #1708 º¼·Ï²®Áú Platinum V
// convex_hull Standard O(nlgn)
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
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
const int MAX = 100011;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
struct Point {
	ll x, y, p, q;
	Point() {}
	Point(ll x, ll y, ll p = 0, ll q = 0)
		:x(x), y(y), p(p), q(q) {}
	bool operator<(const Point& O) {
		if (q * O.p != p * O.q) return q * O.p < p* O.q;
		if (y != O.y)return y < O.y;
		return x < O.x;
	}
};
Point a[MAX];
ll ccw(Point p1, Point p2, Point p3) {
	return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}
int N;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i].x >> a[i].y;
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
	cout << S.size() << "\n";
}