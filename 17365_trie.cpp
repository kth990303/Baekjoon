// 211123 #17365 ∫∞¥Ÿ¡Ÿ Platinum III
// O(MAX_LEN * str.length())
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
int N;
ll d[200003];
struct Node {
	bool end;
	int branch[26];
	int child[26];
	Node() {
		end = false;
		fill(branch, branch + 26, 0);
		fill(child, child + 26, -1);
	}
};
vector<Node> trie;
string str;
void insert(string& s, int idx, int cur) {
	if (idx >= s.length()) {
		trie[cur].end = true;
		return;
	}
	int x = s[idx] - 'a';
	if (trie[cur].child[x] == -1) {
		trie[cur].child[x] = trie.size();
		trie.push_back(Node());
	}
	trie[cur].branch[x]++;
	insert(s, idx + 1, trie[cur].child[x]);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	trie.push_back(Node());
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		insert(s, 0, 0);
	}
	cin >> str;
	int x = str[0] - 'a';
	int cur = 0;
	for (int i = 0; i < str.length(); i++) {
		x = str[i] - 'a';
		ll num = (i ? d[i - 1] : 1);
		int tmp = trie[0].child[x];
		for (int j = i + 1; j < str.length(); j++) {
			int tmpx = str[j] - 'a';
			if (tmp >= trie.size() || !trie[tmp].branch[tmpx]) break;
			d[j] += num * trie[tmp].branch[tmpx];
			d[j] %= MOD;
			tmp = trie[tmp].child[tmpx];
		}
		if (i) {
			d[i] += num * trie[0].branch[x];
			d[i] %= MOD;
		}
		else d[i] = trie[0].branch[x];
		if (trie[cur].child[x] == -1)
			cur = 0;
		else
			cur = trie[cur].child[x];
	}
	cout << d[str.length() - 1] << "\n";
}