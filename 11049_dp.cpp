// 210130 #11049 ��� ���� ���� Gold III
// similar of #11066 or harder
// 11066�� ũ���� ����ȭ, 11049���� �ȵȴٴ� �Ҹ��� �ִ���
// �̰� ���� �Ҹ��� �� �𸣰���.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
const int INF = INT_MAX;
const int MAX = 501;
int N, R, C, d[MAX][MAX];
pair<int, int> p[MAX];
int dp(int l, int r) {
	int& ret = d[l][r];
	if (ret != -1)
		return ret;
	if (l==r)
		return ret = 0;
	ret = INF;
	// A~I, I+1~R
	// look like bottom-up!
	for (int i = l; i < r; i++) {
		ret = min(ret, dp(l, i) + dp(i + 1, r)
			+ p[l].first * p[i].second * p[r].second);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, N - 1) << "\n";
}