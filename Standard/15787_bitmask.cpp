// 210812 #15787 기차가 어둠을 헤치고 은하수를 Silver II
// bitmasking
#include <iostream>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 100001;
int N, M, d[MAX], visit[1 << 20], ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	while (M--) {
		int ch, i, x;
		cin >> ch;
		if (ch == 1) {
			cin >> i >> x;
			x--;
			d[i] |= (1 << x);
		}
		else if (ch == 2) {
			cin >> i >> x;
			x--;
			d[i] &= ~(1 << x);
		}
		else if (ch == 3) {
			cin >> i;
			d[i] <<= 1;
			d[i] &= ~(1 << 20);
		}
		else {
			cin >> i;
			d[i] >>= 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[d[i]]) {
			visit[d[i]] = true;
			ans++;
		}
	}
	cout << ans << "\n";
}