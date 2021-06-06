// 210606 #1017 ¼Ò¼ö ½Ö Platinum III
// bipartite_matching
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 51;
const int MAX_V = 2001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, d[MAX_V];
vector<int> a, v1, v2, ans, v[MAX_V];
bool used[MAX_V], isPrime[MAX_V];
void sieve() {
	fill(isPrime, isPrime + MAX_V, true);
	for (int i = 2; i * i < MAX_V; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j < MAX_V; j += i) {
			isPrime[j] = false;
		}
	}
}
bool dfs(int cur) {
	for (auto i : v[cur]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs(d[i])) {
			d[i] = cur;
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
	a.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	if (a[0] % 2) {
		for (int i = 0; i < N; i++) {
			if (a[i] % 2)
				v1.push_back(a[i]);
			else
				v2.push_back(a[i]);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (a[i] % 2)
				v2.push_back(a[i]);
			else
				v1.push_back(a[i]);
		}
	}
	if (v1.size() != v2.size()) {
		cout << -1 << "\n";
		return 0;
	}
	sieve();
	for (int i = 1; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			int n = v1[i] + v2[j];
			if (isPrime[n]) {
				v[v1[i]].push_back(v2[j]);
			}
		}
	}
	for (int j = 0; j < v2.size(); j++) {
		fill(d, d + MAX_V, 0);
		int n = v1[0] + v2[j];
		if (isPrime[n]) {
			v[v1[0]].clear();
			v[v1[0]].push_back(v2[j]);
			used[v2[j]] = true;
			d[v2[j]] = v1[0];
			int ret = 0;
			for (int i = 1; i < v1.size(); i++) {
				fill(used, used + MAX_V, false);
				if (dfs(v1[i]))
					ret++;
			}
			if (ret == v2.size() - 1)
				ans.push_back(v2[j]);
		}
	}
	if (ans.empty()) {
		cout << -1 << "\n";
		return 0;
	}
	sort(all(ans));
	for (auto i : ans) {
		cout << i << " ";
	}
}