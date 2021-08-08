// 210808 #13505 µÎ ¼ö XOR Platinum III
// Trie. Why? -> all number memory. Only bits and check all number O(N*32)
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 100001;
int N, a[MAX], ans;
struct Trie {
	Trie* next[2];
	int branch;
	bool end;
	Trie() :branch(0), end(false) {
		fill(next, next + 2, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 2; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(string& s, int idx) {
		if (idx >= s.length()) {
			end = true;
			return;
		}
		int x = s[idx] - '0';
		if (!next[x]) {
			next[x] = new Trie();
			branch++;
		}
		next[x]->insert(s, idx + 1);
	}
	void find(string& s, int idx) {
		if (end)
			return;
		int x = s[idx] - '0';
		if (next[1 - x]) {
			s[idx] = '1';
			next[1 - x]->find(s, idx + 1);
		}
		else {
			s[idx] = '0';
			next[x]->find(s, idx + 1);
		}
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	Trie* root = new Trie();
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		int n = a[i];
		string s;
		for (int j = 0; j < 32; j++) {
			if (n % 2)
				s += '1';
			else
				s += '0';
			n /= 2;
		}
		reverse(all(s));
		root->insert(s, 0);
	}
	for (int i = 0; i < N; i++) {
		int n = a[i];
		string s;
		for (int j = 0; j < 32; j++) {
			if (n % 2)
				s += '1';
			else
				s += '0';
			n /= 2;
		}
		reverse(all(s));
		root->find(s, 0);
		int ret = 0;
		for (int i = 0; i < 32; i++) {
			if (s[i] == '1')
				ret |= (1 << (31 - i));
		}
		ans = max(ans, ret);
	}
	cout << ans << "\n";
}