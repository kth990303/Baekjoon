// 210204 #5670 ÈÞ´ëÆù ÀÚÆÇ Platinum IV
// Trie (Length very small and use tree -> trie)
// why platinum IV? (gold I ~ platinum V)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100001;
const int MAX_L = 81;
int N;
struct Trie {
	Trie* next[26];
	int branch;
	bool end;
	Trie(): branch(0), end(false) {
		fill(next, next + 26, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(string& s, int idx) {
		if (idx >= s.length()) {
			end = true;
			return;
		}
		int x = s[idx] - 'a';
		if (!next[x]) {
			next[x] = new Trie();
			branch++;
		}
		next[x]->insert(s, idx + 1);
	}
	int find(string& s, int idx, int cnt) {
		if (end && s.length() == idx)
			return cnt;
		int ret = 0;
		int x = s[idx] - 'a';
		// case work is important
		if (branch >= 2 || (end && branch == 1) || !idx)
			ret = next[x]->find(s, idx + 1, cnt + 1);
		else
			ret += next[x]->find(s, idx + 1, cnt);
		return ret;
	}
};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cout << fixed;
	cout.precision(2);

	while (cin >> N) {
		vector<string> str(N);
		double ans = 0;
		Trie* root = new Trie();
		for (int i = 0; i < N; i++) {
			cin >> str[i];
			root->insert(str[i], 0);
		}
		for (int i = 0; i < N; i++) {
			ans += root->find(str[i], 0, 0);
		}
		cout << ans / (double)(N) << "\n";
		delete root;
	}
}