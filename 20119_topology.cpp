// 210627 #20119 클레어와 물약 Gold II
// topology + indexing
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 200001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, L, in[MAX], a[MAX];
vector<int> c[MAX];
vector<int> ans;
bool visit[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	fill(in, in + N, INF);
	for (int i = 0; i < M; i++) {
		cin >> in[i];
		for (int j = 0; j < in[i]; j++) {
			int n;
			cin >> n;
			c[n].push_back(i);
		}
		// same medicine recipe
		// so new indexing
		cin >> a[i];
	}
	cin >> L;
	queue<int> q;
	for (int i = 0; i < L; i++) {
		int n;
		cin >> n;
		if (visit[n])
			continue;
		ans.push_back(n);
		q.push(n);
		for (auto j : c[n]) {
			in[j]--;
			if (!in[j]) {
				ans.push_back(a[j]);
				q.push(a[j]);
			}
		}
		visit[n] = true;
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visit[cur])
			continue;
		for (auto i : c[cur]) {
			in[i]--;
			if (!(in[i])) {
				ans.push_back(a[i]);
				q.push(a[i]);
			}
		}
		visit[cur] = true;
	}
	sort(all(ans));
	press(ans);
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
}