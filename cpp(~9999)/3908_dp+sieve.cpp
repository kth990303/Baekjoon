// 210124 #3908 서로 다른 소수의 합 Gold III
// sieve + dp
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1121;
int N, K, d[188][MAX][15];
bool prime[MAX];
vector<int> v;
void sieve() {
	fill(prime, prime + MAX, true);
	for (int i = 2; i * i < MAX; i++) {
		if (!prime[i])
			continue;
		for (int j = i * 2; j < MAX; j += i) {
			prime[j] = false;
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (prime[i])
			v.push_back(i);
	}
}
// num: to exclude duplicates
// cur: N
// cnt: K
// Not MLE (1120*15*14)

// Why K-=1 is AC, and 0+1+1+1=>K is WA???
int dp(int num, int cur, int cnt) {
	int& ret = d[num][cur][cnt];
	if (ret != -1)
		return ret;
	if (cur == 0 && cnt == 0)
		return ret = 1;
	if (num == v.size())
		return ret = 0;
	if (cnt <= 0)
		return ret = 0;
	ret = dp(num + 1, cur, cnt);
	if (cur - v[num] >= 0)
		ret += dp(num + 1, cur - v[num], cnt - 1);
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	sieve();
	memset(d, -1, sizeof(d));
	while (t--) {
		cin >> N >> K;
		cout << dp(0, N, K) << "\n";
	}
}