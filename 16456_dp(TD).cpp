// 201227 #16456 �ϿͿ� ���л�» �Ͽ��̷� ���� �ŽÿͿ�~ Silver I
// DP(TD) �ð����⵵: O(N)
// ���Ҿ� ����̶� ũ�� �ٸ� �ٰ� ����
#include <iostream>
using namespace std;
const int MAX = 50001;
typedef long long ll;
const ll MOD = 1e9 + 9;
ll N, d[MAX];
ll dp(ll cur) {
	ll& ret = d[cur];
	if (ret != -1)
		return ret;
	if (cur + 2 == N - 1)
		return ret = 2;
	if (cur + 1 >= N - 1)
		return ret = 1;
	ret = 0;
	if (cur + 1 < N) {
		ret += dp(cur + 1);
		ret %= MOD;
	}
	if (cur + 3 < N) {
		ret += dp(cur + 3);
		ret %= MOD;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(d, d + MAX, -1);
	cout << dp(0) << "\n";
}