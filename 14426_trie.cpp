// 200928 #14426 접두사 찾기 Silver IV
// 트라이 풀이
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 26;
int N, M, ans;
struct Trie {
	Trie* nxt[MAX];
	bool end;
	bool hasLeaf;
	Trie() {
		fill(nxt, nxt + MAX, nullptr);
		end = hasLeaf = false;
	}
	~Trie() {
		for (int i = 0; i < MAX; i++) {
			if (nxt[i])
				delete nxt[i];
		}
	}
	void insert(const char* str) {
		if (*str == '\0') {
			end = true;
			return;
		}
		int x = *str - 'a';
		if (!nxt[x]) {
			nxt[x] = new Trie();
		}
		hasLeaf = true;
		nxt[x]->insert(str + 1);
	}
	bool check(const char* word) {
		if (*word == '\0') {
			return true;
		}
		int x = *word - 'a';
		if (!nxt[x] || !hasLeaf)
			return false;
		return nxt[x]->check(word + 1);
	}
};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	Trie* root = new Trie;
	while (N--) {
		char s[501];
		cin >> s;
		root->insert(s);
	}
	while (M--) {
		char w[501];
		cin >> w;
		if (root->check(w))
			ans++;
	}
	cout << ans << "\n";
}