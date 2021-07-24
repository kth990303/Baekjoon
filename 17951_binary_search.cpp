// 210724 #17951 흩날리는 시험지 속에서 내 평점이 느껴진거야 Gold V
// binary_search
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, K, a[MAX], ans = INF;
int solve(int s, int e) {
	while (s <= e) {
		int mid = (s + e) / 2, ret = 0, cnt = 1;
		for (int i = 0; i < N; i++) {
			ret += a[i];
			if (ret > mid) {
				ret = 0;
				cnt++;
			}
		}
		if (cnt == K) {
			ans = mid;
		}
		if (cnt > K)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	int s = 0, e = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		s = max(s, a[i]);
		e += a[i];
	}
	cout << solve(s, e) << "\n";
}