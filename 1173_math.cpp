#include <iostream>
using namespace std;
int N, m, M, T, R;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> m >> M >> T >> R;
	int t1 = 0, t2 = 0, now = m;
	// Exception
	if (M - m < T) {
		cout << -1 << "\n";
		return 0;
	}
	while (t1 != N) {
		if (now + T <= M) {
			t1++; t2++;
			now += T;
		}
		else {
			now -= R;
			t2++;
			if (now < m)
				now = m;
		}
	}
	cout << t2 << "\n";
}