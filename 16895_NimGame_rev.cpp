#include <iostream>
using namespace std;
const int MAX = 1001;
int N, p[MAX], ans, cnt;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		ans ^= p[i];
	}
	if (!ans) {
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		int tmpAns = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			tmpAns ^= p[j];
		}
		for (int j = 1; j <= p[i]; j++) {
			int tmp = p[i] - j;
			if (!(tmpAns ^ tmp))
				cnt++;
		}
	}
	cout << cnt << "\n";
}