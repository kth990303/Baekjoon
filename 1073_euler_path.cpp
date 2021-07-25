// 210725 #1073 µµ¹Ì³ë Platinum IV
// euler-path
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
const int MAX = 46;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
ll N, ans = 1, d[11] = { 1,0, };
int in[10];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		// all indegrees are even
		in[n / 10]++;
		in[n % 10]++;
	}
	for (ll i = 2; i <= N; i++) {
		if (i % 2)
			continue;
		// can go (i-1) edges, extra i-2 edges
		d[i] = (i - 1) * d[i - 2];
	}
	for (int i = 0; i < 10; i++) {
		ans *= d[in[i]];
	}
	cout << ans << "\n";
}