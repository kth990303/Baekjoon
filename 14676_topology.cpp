// 220111 #14676 ����»���? Gold III
// indegree graph
// update 22.01.11.
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
int N, M, K, indegree[MAX], cnt[MAX];
vector<int> v[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	while (K--) {
		int ch, a;
		cin >> ch >> a;
		if (ch == 1) {
			if (indegree[a] > 0) {
				cout << "Lier!\n";
				return 0;
			}
			cnt[a]++;
			if (cnt[a] > 1)continue;
			for (auto i : v[a]) {
				indegree[i]--;
			}
		}
		else {
			if (cnt[a] <= 0) {
				cout << "Lier!\n";
				return 0;
			}
			cnt[a]--;
			if (cnt[a])continue;
			for (auto i : v[a]) {
				indegree[i]++;
			}
		}
	}
	cout << "King-God-Emperor\n";
}