#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
int N;
vector<int> v[MAX];
bool visit[MAX];
bool dfs(int s, int e) {
	visit[s] = true;
	for (auto i : v[s]) {
		if (i == e)
			return true;
		if (!visit[i]) {
			if (dfs(i, e))
				return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			if (num) {
				v[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fill(visit, visit + MAX, false);
			if (dfs(i, j)) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}