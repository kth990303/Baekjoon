// 210107 #2352 반도체 설계 Gold III
// dp? -> O(N^2) TLE
// binary_search (aka LIS)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 40001;
int N;
vector<int> v, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		int cur = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
		if (cur < ans.size())
			ans[cur] = v[i];
		else
			ans.push_back(v[i]);
	}
	cout << ans.size() << "\n";
}