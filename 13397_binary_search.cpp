// 210620 #13397 구간 나누기 2 Gold IV
// binary_search 
// ganeung? ganeung? ganeung~ mode
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 5001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, a[MAX], ans;
int solve(int s, int e) {
	int ret = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 1, n1 = a[0], n2 = a[0];
		for (int i = 0; i < N; i++) {
			n1 = min(n1, a[i]);
			n2 = max(n2, a[i]);
			if (n2 - n1 > mid) {
				n1 = a[i];
				n2 = a[i];
				cnt++;
			}
		}
		if (cnt <= M) {
			ret = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int s = 0, e = 10000;
	cout << solve(s, e) << "\n";
}