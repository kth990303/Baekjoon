// 210522 #15971 µÎ ·Îº¿ Gold V
// dfs + greedy
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
int N, A, B, M;
vector<pi> v[MAX];
bool visit[MAX];
int dfs(int cur) {
	if (cur == B)
		return 0;
	int ret = INF;
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.second]) {
			int tmp = dfs(i.second) + i.first;
			if (tmp < ret) {
				ret = tmp;
				M = max(M, i.first);
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> A >> B;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}
	cout << dfs(A) - M << "\n";
}