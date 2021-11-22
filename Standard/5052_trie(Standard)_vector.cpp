// 211123 #5052 전화번호목록 Gold IV
// trie(Standard) vector 32ms, pointer: 160ms
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
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1000011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t, N;
struct Node {
	bool end;
	int child[10];
	Node() {
		end = false;
		fill(child, child + 10, -1);
	}
};
bool flag;
vector<Node> trie;
void insert(string& s, int idx, int cur) {
	if (idx >= s.length()) {
		trie[cur].end = true;
		return;
	}
	int x = s[idx] - '0';
	if (trie[cur].end) flag = false;
	if (idx == s.length() - 1 && trie[cur].child[x] != -1)flag = false;
	if (trie[cur].child[x] == -1) {
		trie[cur].child[x] = trie.size();
		trie.push_back(Node());
	}
	insert(s, idx + 1, trie[cur].child[x]);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> N;
		trie.clear();
		trie.push_back(Node());
		flag = true;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			insert(s, 0, 0);
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}