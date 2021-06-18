// 210618 #2002 Ãß¿ù Silver I
// map O(N^2) bruteforce
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
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, ans;
bool visit[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	map<string, int> m;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m[s] = i;
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int idx = m.find(s)->second;
		for (int j = 0; j < idx; j++) {
			if (!visit[j]) {
				ans++;
				break;
			}
		}
		visit[idx] = true;
	}
	cout << ans << "\n";
}