// 201228 #5557 1학년 Gold V
// dp(TD)
#include <iostream>
#include <cstring>
const int MAX = 101;
using namespace std;
typedef long long ll;
ll N, a[MAX], d[MAX][21];
ll dp(int cur, int num) {
	ll& ret = d[cur][num];
	if (ret != -1)
		return ret;
	if (cur == N - 1) {
		if (num == a[cur])
			return ret = 1;
		else
			return ret = 0;
	}
	ret = 0;
	if (num + a[cur] <= 20)
		ret += dp(cur + 1, num + a[cur]);
	// cur=0일 땐 자기 자신이므로, 한 경우(자기 자신 더하는 경우)만 계산
	if (cur && num - a[cur] >= 0)
		ret += dp(cur + 1, num - a[cur]);
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}