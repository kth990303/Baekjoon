// 200911 #15966 �������� Silver II
// kks227�� Ǯ�̹�� ����
// ž�ٿ����� upper_bound �̿�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, a[MAX], cache[MAX];
vector<int> v[1000002];	// 0~1000000
int dp(int s) {
	int& ret = cache[s];
	if (ret != -1)
		return ret;
	int i = a[s] + 1;
	// idx�� ����
	int nxt = upper_bound(v[i].begin(), v[i].end(), s) - v[i].begin();
	if (nxt == v[i].size())
		return ret = 1;
	else
		return ret = dp(v[i][nxt]) + 1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(cache, cache + MAX, -1);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	int ans = 1;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(i));
	}
	cout << ans << "\n";
}