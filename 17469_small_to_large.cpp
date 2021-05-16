// 210516 #17469 Æ®¸®ÀÇ »ö±ò°ú Äõ¸® Platinum III
// offline_query + small_to_large + union_find
// O(Nlg^2N)
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int MAX = 100001;
int N, Q, p[MAX], parent[MAX];
vector<pair<int, int>> query;
set<int> S[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
// O(lgn) * small_to_large => O(lg^2n)
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	// small to large -> set insert o(nlgn)
	if (S[a].size() <= S[b].size())
		swap(a, b);
	p[b] = a;
	for (auto i : S[b]) {
		S[a].insert(i);
	}
	S[b].clear();
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		int n;
		cin >> n;
		parent[i] = n;
	}
	for (int i = 1; i <= N; i++) {
		p[i] = i;
		int n;
		cin >> n;
		S[i].insert(n);
	}
	query.resize(N + Q - 1);
	vector<int> ans;
	for (int i = 0; i < N + Q - 1; i++) {
		cin >> query[i].first >> query[i].second;
	}
	for (int i = query.size() - 1; i >= 0; i--) {
		int ch = query[i].first;
		int a = query[i].second;
		if (ch == 1) {
			merge(parent[a], a);
		}
		else {
			ans.push_back(S[find(a)].size());
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << "\n";
	}
}