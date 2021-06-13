// 210613 #21276 계보 복원가 호석 Gold IV
// topology_sort
// not dfs because it doesn't have direct connect vertex
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, in[MAX], cnt;
map<string, int> m;
vector<string> a;
vector<int> v[MAX], ans[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(all(a));
	for (int i = 0; i < N; i++) {
		m.insert({ a[i], i });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string n1, n2;
		cin >> n1 >> n2;
		in[m[n1]]++;
		v[m[n2]].push_back(m[n1]);
	}
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (!in[i]) {
			q.push(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < N; i++) {
		if (!in[i]) {
			cout << a[i] << " ";
		}
	}
	cout << "\n";
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (auto i : v[t]) {
			if (--in[i] == 0) {
				q.push(i);
				ans[t].push_back(i);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << " " << ans[i].size() << " ";
		sort(all(ans[i]));
		for (auto j : ans[i]) {
			cout << a[j] << " ";
		}
		cout << "\n";
	}
}