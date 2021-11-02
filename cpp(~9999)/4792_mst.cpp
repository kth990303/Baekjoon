// 210608 #4792 레드 블루 스패닝 트리 Platinum III
// mst (proof is difficult)
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
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, K, p[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (a > b)
		swap(a, b);
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N >> M >> K) {
		if (!N && !M && !K)
			break;
		int ans1 = 0, ans2 = 0;
		vector<pair<char, pi>> q(M);
		for (int i = 0; i < M; i++) {
			cin >> q[i].first >> q[i].second.first >> q[i].second.second;
		}
		for (int t = 0; t < 2; t++) {
			vector<pair<int, pi>> v;
			for (int i = 1; i <= N; i++) {
				p[i] = i;
			}
			for (int i = 0; i < q.size(); i++) {
				char ch = q[i].first;
				int a = q[i].second.first;
				int b = q[i].second.second;
				int cost = 0;
				if (!t && ch == 'B')
					cost++;
				else if (t && ch == 'R')
					cost++;
				v.push_back({ cost, {a,b} });
			}
			sort(all(v));
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				int n1 = v[i].second.first;
				int n2 = v[i].second.second;
				int cost = v[i].first;
				if (merge(n1, n2)) {
					cnt++;
					if (!t && cost)
						ans1++;
					else if (t && !cost)
						ans2++;
				}
				if (cnt == N - 1)
					break;
			}
		}
		if (ans1 > K || ans2 < K)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
}