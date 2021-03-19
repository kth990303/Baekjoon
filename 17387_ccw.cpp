// 210319 #17387 선분 교차 2 Gold II
// operator overloading is important 
#include <iostream>
using namespace std;
typedef long long ll;;
struct Point {
	ll x, y;
	bool operator<(const Point& O) {
		if (x != O.x)
			return x < O.x;
		return y < O.y;
	}
	bool operator==(const Point& O) {
		if (x == O.x && y == O.y)
			return true;
		return false;
	}
};
Point p[4];
ll ccw(const Point& p1, const Point& p2, const Point& p3) {
	ll ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	for (int i = 0; i < 4; i++) {
		cin >> p[i].x >> p[i].y;
	}
	ll ans1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
	ll ans2 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);
	if (ans1 <= 0 && ans2 <= 0) {
		if (!ans1 && !ans2) {
			if (p[1] < p[0])
				swap(p[0], p[1]);
			if (p[3] < p[2])
				swap(p[2], p[3]);
			if ((p[0] < p[3] || p[0] == p[3]) && (p[2] < p[1] || p[2] == p[1]))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else
			cout << 1 << "\n";
	}
	else
		cout << 0 << "\n";
}