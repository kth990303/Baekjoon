// 210407 #14676 영우는 사기꾼? Gold IV
// indegree like topology sort
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
			for (auto i : v[a]) {
				indegree[i]++;
			}
		}
	}
	cout << "King-God-Emperor\n";
}