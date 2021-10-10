// 211010 #3088 화분 부수기 Gold V
// greedy 
// Necessary break first flower
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 300011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, cnt[1000001], ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!cnt[a] && !cnt[b] && !cnt[c])
			ans++;
		cnt[a]++;
		cnt[b]++;
		cnt[c]++;
	}
	cout << ans << "\n";
}