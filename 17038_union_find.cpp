// 211119 #17038 The Great Revegetation (Silver) (Gold II)
// 2-sat + union_find
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 200011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e6;
int N, M, p[MAX];
map<int, int> m;
int find(int a) {
	if (a == p[a])return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return false;
	if (a > b)swap(a, b);
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N * 2; i++)p[i] = i;
	while (M--) {
		char ch;
		int n1, n2;
		cin >> ch >> n1 >> n2;
		if (ch == 'S') {
			merge(n1, n2);
			merge(n1 + N, n2 + N);
		}
		else {
			merge(n1, n2 + N);
			merge(n2, n1 + N);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (find(i) == find(i + N)) {
			cout << 0;
			return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		merge(i, i + N);
	}
	for (int i = 1; i <= N; i++) {
		m[find(i)]++;
	}
	cout << 1;
	for (int i = 0; i < m.size(); i++) {
		cout << 0;
	}
}