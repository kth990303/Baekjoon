// 210923 #11266 ´ÜÀýÁ¡ Platinum V
// use BCC algorithm -> cnt more than one BCC's node
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 10001;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
int N, M, id, d[MAX], bccNum[MAX];
vector<int> v[MAX], ans;
vector<vector<pi>> BCC;
stack<pi> s;
int dfs(int cur, int prev = -1) {
	d[cur] = id++;
	int parent = d[cur];

	for (auto i: v[cur]) {
		if (i == prev)
			continue;
		if (d[i] < d[cur])
			s.push({ cur, i });
		if (d[i] != -1)
			parent = min(parent, d[i]);
		else {
			int t = dfs(i, cur);
			parent = min(parent, t);
			if (t >= d[cur]) {
				vector<pi> bcc;
				while (!s.empty()) {
					pi e = s.top();
					s.pop();
					bcc.push_back(e);
					int size = BCC.size();
					if (bccNum[e.first] != -1 && bccNum[e.first] != size)
						ans.push_back(e.first);
					if (bccNum[e.second] != -1 && bccNum[e.second] != size)
						ans.push_back(e.second);
					bccNum[e.first] = bccNum[e.second] = size;
					if (e.first == cur && e.second == i)
						break;
				}
				BCC.push_back(bcc);
			}
		}
	}
	return parent;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	fill(d, d + N, -1);
	fill(bccNum, bccNum + N, -1);
	for (int i = 0; i < N; i++) {
		if (d[i] == -1)
			dfs(i);
	}
	sort(all(ans));
	press(ans);
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
}