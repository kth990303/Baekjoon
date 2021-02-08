// 210208 #1021 회전하는 큐 Silver IV
// deque
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int N, M, ans;
deque<int> d;
void left() {
	int t = d.front();
	d.push_back(t);
	d.pop_front();
	ans++;
}
void right() {
	int b = d.back();
	d.push_front(b);
	d.pop_back();
	ans++;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}
	while (M--) {
		int n, idx = 0;
		cin >> n;
		for (int i = 0; i < d.size(); i++) {
			if (d[i] == n) {
				idx = i;
				break;
			}
		}
		if (idx < d.size() - idx) {
			while (1) {
				if (d.front() == n) {
					d.pop_front();
					break;
				}
				left();
			}
		}
		else {
			while (1) {
				if (d.front() == n) {
					d.pop_front();
					break;
				}
				right();
			}
		}
	}
	cout << ans << "\n";
}