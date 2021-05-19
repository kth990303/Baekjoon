// 210519 #16934 게임 닉네임 Platinum IV
// Trie: 136ms, map: 452ms
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 100001;
int N;
struct Trie {
	Trie* next[26];
	int branch;
	int end;
	Trie() : branch(0), end(0) {
		fill(next, next + 26, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(string& s, int idx, bool flag) {
		if (idx >= s.length()) {
			end++;
			if (end > 1)
				cout << end;
			cout << "\n";
			return;
		}
		int x = s[idx] - 'a';
		if (!flag)
			cout << s[idx];
		// if new str idx
		if (!next[x]) {
			next[x] = new Trie();
			branch++;
			// flag is true, than not insert nickname
			flag = true;
		}
		next[x]->insert(s, idx + 1, flag);
	}
};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	Trie* root = new Trie();
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		root->insert(s, 0, false);
	}
	delete root;
}