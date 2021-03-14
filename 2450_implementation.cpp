// 210314 #2450 ¸ð¾ç Á¤µ· Gold II
// Implementation
// why dp tag?
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int INF = 1e9 + 7;
int N, a[MAX], b[MAX], cnt[4];
// order kinds
int o[6][3] = { {1,2,3}, {1,3,2}, {2,1,3}, 
	{2,3,1}, {3,1,2}, {3,2,1} };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int ans = INF;
	for (int i = 0; i < 6; i++) {
		int ret = 0;
		int s = 0;
		// first group, all changes
		for (int k = s; k < cnt[o[i][0]]; k++) {
			if (a[k] != o[i][0])
				ret++;
		}
		s += cnt[o[i][0]];
		// if nor ordering, change
		int tmp1 = 0, tmp2 = 0;
		for (int k = s; k < s+cnt[o[i][1]]; k++) {
			if (a[k] == o[i][2])
				tmp1++;
		}
		s += cnt[o[i][1]];
		for (int k = s; k < s+cnt[o[i][2]]; k++) {
			if (a[k] == o[i][1])
				tmp2++;
		}
		ret += max(tmp1, tmp2);
		ans = min(ans, ret);
	}
	cout << ans << "\n";
}