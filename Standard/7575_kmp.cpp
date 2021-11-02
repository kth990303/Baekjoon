// 210808 #7575 바이러스 Platinum V
// KMP
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 101;
int N, M;
vector<int> v[MAX], p[2001];
vector<int> fail(int cur) {
	int j = 0;
	vector<int> pi(v[cur].size(), 0);
	for (int i = 1; i < v[cur].size(); i++) {
		while (j > 0 && v[cur][i] != v[cur][j]) {
			j = pi[j - 1];
		}
		if (v[cur][i] == v[cur][j])
			pi[i] = ++j;
	}
	return pi;
}
bool kmp(int cur, int n) {
	vector<int> pi = fail(cur);
	int j = 0;
	for (int i = 0; i < v[cur].size(); i++) {
		while (j > 0 && v[cur][i] != p[n][j]) {
			j = pi[j - 1];
		}
		if (v[cur][i] == p[n][j]) {
			if (j == M - 1)
				return true;
			j++;
		}
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		while (n--) {
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	for (int i = 0; i <= v[0].size()-M; i++) {
		for (int j = 0; j < M; j++) {
			p[i*2].push_back(v[0][i + j]);
		}
		for (int j = M - 1; j >= 0; j--) {
			p[i * 2 + 1].push_back(v[0][i + j]);
		}
	}
	for (int i = 0; i <= v[0].size() - M; i++) {
		bool flag = true;
		for (int j = 1; j < N; j++) {
			if (!kmp(j, i * 2) && !kmp(j, i * 2 + 1)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}