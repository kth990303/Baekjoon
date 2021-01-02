// 210102 #12852 1로 만들기2 Silver I
// dp + trace
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
int N, d[MAX], p[MAX];
vector<int> ans;
int dp(int cur) {
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	if (cur == 1)
		return ret = 0;
	ret = dp(cur - 1) + 1;
	if (!(cur % 3) && ret > dp(cur / 3) + 1) {
		ret = dp(cur / 3) + 1;
		p[cur] = 3;	// update
	}
	if (!(cur % 2) && ret > dp(cur / 2) + 1) {
		ret = dp(cur / 2) + 1;
		p[cur] = 2;	// update
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(d, d + MAX, -1);
	cout << dp(N) << "\n";	// normal dp
	ans.push_back(N);
	// tracing
	while (1) {
		if (N == 1)
			break;
		if (!p[N]) {
			ans.push_back(N - 1);
			N--;
		}
		else if (p[N] == 2) {
			ans.push_back(N / 2);
			N /= 2;
		}
		else {
			ans.push_back(N / 3);
			N /= 3;
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}