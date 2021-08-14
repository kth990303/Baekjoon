// 210814 #3665 최종순위 Gold I
// topology_sort O(4TM)
// we keep in mind that {a->b->c->d} can {a->b}, {a->c}, {a->d}
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 501;
int N, M, a[MAX], in[MAX];
vector<int> v[MAX];
bool order[MAX][MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		for (auto& i : v)
			i.clear();
		fill(in, in + MAX, 0);
		memset(order, false, sizeof(order));
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> a[i];
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				order[a[i]][a[j]] = true;
			}
		}
		cin >> M;
		while (M--) {
			int n1, n2;
			cin >> n1 >> n2;
			if (order[n1][n2]) {
				order[n1][n2] = false;
				order[n2][n1] = true;
			}
			else {
				order[n2][n1] = false;
				order[n1][n2] = true;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (order[i][j]) {
					v[i].push_back(j);
					in[j]++;
				}
			}
		}
		queue<int> q;
		vector<int> ans;
		for (int i = 1; i <= N; i++) {
			if (!in[i]) {
				q.push(i);
				ans.push_back(i);
			}
		}
		while (!q.empty()) {
			if (q.size() > 1) {
				cout << "?\n";
				break;
			}
			int cur = q.front();
			q.pop();
			for (auto i : v[cur]) {
				if (!in[i])
					continue;
				if (--in[i] == 0) {
					q.push(i);
					ans.push_back(i);
				}
			}
		}
		if (ans.size() != N)
			cout << "IMPOSSIBLE\n";
		else if (q.empty()) {
			for (auto i : ans)
				cout << i << " ";
			cout << "\n";
		}
	}
}