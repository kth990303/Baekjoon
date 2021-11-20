// 211120 #23568 Find the House Silver IV
// icpc 2021 Seoul Regional 
// map, simulation
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 10011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, S, now;
map<int, int> m;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, d, e = 0;
		char dir;
		cin >> s >> dir >> d;
		if (dir == 'L')e = s - d;
		else e = s + d;
		m[s] = e;
	}
	cin >> S;
	now = S;
	for (int i = 0; i < N; i++) {
		now = m[now];
	}
	cout << now << "\n";
}