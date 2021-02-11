#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int N;
// Tree and HashMap
struct Trie {
	map<string, Trie*> M;
	void insert(vector<string> v, int depth) {
		if (depth == v.size()) {
			return;
		}
		// if not v[depth] in M
		if (!M.count(v[depth]))
			M[v[depth]] = new Trie();
		M[v[depth]]->insert(v, depth + 1);
	}
	void find(int depth) {
		if (M.empty())
			return;
		for (auto it = M.begin(); it != M.end(); it++) {
			for (int i = 0; i < depth; i++) {
				cout << "--";
			}
			cout << it->first << "\n";
			M[it->first]->find(depth + 1);
		}
	}
};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	Trie* root = new Trie();
	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		vector<string> v;
		v.resize(M);
		for (int i = 0; i < M; i++) {
			cin >> v[i];
		}
		root->insert(v, 0);
	}
	root->find(0);
}