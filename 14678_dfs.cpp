// 210902 #14678 어그로 끌린 영선 Gold II
// tree isomorphic -> all distances are same whatever root
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 1000001;
int N, ans, in[MAX], dep[MAX];
vector<int> v[MAX];
bool visit[MAX];
void dfs(int cur, int h) {
	dep[cur] = h;
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			dfs(i, h + 1);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		in[a]++; in[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (in[i] != 1)
			dfs(i, 0);
	}
	int ans1 = 0, ans2 = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 1) {
			cnt++;
			if (dep[i] % 2)
				ans1++;
			else
				ans2++;
		}
	}
	// corner case: case_work
	if (N == 1)
		cout << 0 << "\n";
	else if (N == 2)
		cout << 1 << "\n";
	else if (cnt == N - 1)
		cout << N - 2 << "\n";
	else
		cout << max(ans1, ans2) << "\n";
}