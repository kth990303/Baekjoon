// 200904 #14425 문자열 집합 Silver III
// 공간복잡도: N(10000)*26(소문자)*길이(500)...ㅋ
// string STL 필요없는 버전
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int LEN_MAX = 26;
int N, M, ans;
struct Trie {
	Trie* next[LEN_MAX];
	bool end;
	bool hasleaf;
	Trie() {
		fill(next, next + LEN_MAX, nullptr);
		end = hasleaf = false;
	}
	~Trie() {
		for (int i = 0; i < LEN_MAX; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* str) {
		if (*str == '\0') {
			end = true;
			return;
		}
		int x = *str - 'a';
		if (!next[x]) {
			next[x] = new Trie();
			hasleaf = true;
		}
		next[x]->insert(str + 1);
	}
	bool check(const char* word) {
		if (*word == '\0') {
			if (end)
				return true;
			else
				return false;
		}
		int x = *word - 'a';
		if (!next[x] || end || !hasleaf)
			return false;

		return next[x]->check(word + 1);
	}
};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	Trie* root = new Trie;
	for (int i = 0; i < N; i++) {
		char s[501];
		cin >> s;
		root->insert(s);
	}
	for (int i = 0; i < M; i++) {
		char w[501];
		cin >> w;
		if (root->check(w))
			ans++;
	}
	cout << ans << "\n";
}