// 210123 #1963 소수 경로 Gold V
// sieve (소수) + bfs (최단경로)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int MAX = 10001;
bool prime[MAX], visit[MAX];
// sieve O(log(10000))
void sieve() {
	fill(prime, prime + MAX, true);
	for (int i = 2; i * i < 10000; i++) {
		if (!prime[i])
			continue;
		for (int j = i * 2; j < 10000; j += i) {
			prime[j] = false;
		}
	}
}
// bfs to get minimum distance road
int bfs(string n, string b) {
	queue<pair<int, string>> q;
	q.push({ 0, n });
	visit[stoi(n)] = true;
	while (!q.empty()) {
		string x = q.front().second;
		int time = q.front().first;
		q.pop();
		if (x == b)
			return time;
		// change string
		string s = x;
		// first digit
		for (int i = 1; i < 10; i++) {
			// string
			if (s[0] != i+'0') {
				// change first digit
				s[0] = i + '0';
				// not visit && prime
				if (!visit[stoi(s)] && prime[stoi(s)]) {
					visit[stoi(s)] = true;
					q.push({ time + 1, s });
				}
			}
		}
		// second digit, third digit, fourth digit
		for (int j = 1; j <= 3; j++) {
			string s = x;
			for (int i = 0; i < 10; i++) {
				if (s[j] != i + '0') {
					// change digit
					s[j] = i + '0';
					if (!visit[stoi(s)] && prime[stoi(s)]) {
						visit[stoi(s)] = true;
						q.push({ time + 1, s });
					}
				}
			}
		}
	}
	// Impossible: -1
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	sieve();
	while (t--) {
		fill(visit, visit + MAX, false);
		int a, b;
		cin >> a >> b;
		// change string because change the digit easier
		int ans = bfs(to_string(a), to_string(b));
		if (ans == -1) {
			cout << "Impossible\n";
		}
		else
			cout << ans << "\n";
	}
}