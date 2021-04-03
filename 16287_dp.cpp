// 210403 #16287 Parcel Gold I
// idea is difficult. tag: dp, but I think it's like more impl.
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 5001;
int W, N, a[MAX];
bool visit[799995];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> W >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] + a[j] <= W && visit[W - a[i] - a[j]]) {
				cout << "YES\n";
				return 0;
			}
		}
		for (int j = 0; j < i; j++) {
			if (a[i] + a[j] <= W && !visit[a[i] + a[j]])
				visit[a[i] + a[j]] = true;
		}
	}
	cout << "NO\n";
}