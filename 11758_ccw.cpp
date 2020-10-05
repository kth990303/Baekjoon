#include <iostream>
using namespace std;
// Point ��ǥ ����ü ����
struct Point {
	int x, y;
};
Point p[3];
// ccw �˰���: ������ ���� �̿�
// s1-s2�� ����� �ݽð�, ������ �ð����. 0�̸� ����.
int ccw(Point p1, Point p2, Point p3) {
	int s1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	int s2 = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	if (s1 > s2) return 1;
	else if (s1 < s2) return -1;
	else return 0;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++) {
		cin >> p[i].x >> p[i].y;
	}
	cout << ccw(p[0], p[1], p[2]) << "\n";
}