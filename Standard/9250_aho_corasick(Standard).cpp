// 210404 #9250 문자열 집합 판별 Platinum II
// aho_corasick: SCOFE festival 2021 used this algorithm
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;
const int MAX_L = 10001;
int N, Q;
struct Trie {
	Trie* next[26];
	Trie* fail;
	bool output;
	Trie() : output(false) {
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
			output = true;
			return;
		}
		int x = s[idx] - 'a';
		if (!next[x]) {
			next[x] = new Trie();
		}
		next[x]->insert(s, idx + 1);
	}
};
void fail(Trie* root) {
	queue<Trie*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Trie* cur = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			Trie* nxt = cur->next[i];
			if (!nxt)
				continue;
			if (root == cur)
				nxt->fail = root;
			else {
				Trie* tmp = cur->fail;
				while (tmp != root && !tmp->next[i])
					tmp = tmp->fail;
				if (tmp->next[i])
					tmp = tmp->next[i];
				nxt->fail = tmp;
			}
			if (nxt->fail->output)
				nxt->output = true;
			q.push(nxt);
		}
	}
}
string solve(string s, Trie* root) {
	vector<pair<int, int>> ret;
	Trie* cur = root;
	for (int i = 0; i < s.length(); i++) {
		int nxt = s[i] - 'a';
		while (cur != root && !cur->next[nxt])
			cur = cur->fail;
		if (cur->next[nxt])
			cur = cur->next[nxt];
		if (cur->output) {
			return "YES";
		}
	}
	return "NO";
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	Trie* root = new Trie();
	while (N--) {
		string s;
		cin >> s;
		root->insert(s, 0);
	}
	fail(root);
	cin >> Q;
	while (Q--) {
		string s;
		cin >> s;
		cout << solve(s, root) << "\n";
	}
	delete root;
}