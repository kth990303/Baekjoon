#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = 1000000007;
int N, a[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			if (!a[i][j])
				a[i][j] = INF;
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (a[i][j] != INF)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}

	return 0;
}