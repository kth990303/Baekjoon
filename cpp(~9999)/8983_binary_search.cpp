// 210124 #8983 »ç³É²Û Gold IV
// binary_search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100001;
int M, N, L, ans;
vector<int> v;
vector<pair<int, int>> animal;
vector<int> ani;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> M >> N >> L;
	v.resize(M);
	animal.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> v[i];	// The y-coordinate is zero anyway
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cin >> animal[i].first >> animal[i].second;
		// A firing line's y - coordinate is zero anyway
		ani.push_back(animal[i].first);
	}
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(v.begin(), v.end(), ani[i]) - v.begin();
		if (abs(v[idx] - ani[i]) + animal[i].second <= L)
			ans++;
		// 2 1 100000000
		// 1 1000000000
		// 2 5
		// ans: 1
		// lower_bound-1: same the key and maximum idx
		else if (idx && abs(v[idx-1] - ani[i]) + animal[i].second <= L)
			ans++;
	}
	cout << ans << "\n";
}