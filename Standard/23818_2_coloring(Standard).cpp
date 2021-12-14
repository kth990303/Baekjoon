// 211214 #23818 원수의원수 Gold I
// 2-coloring Standard
// disjoint_set O((K+Q)lgN)
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
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, K, p[MAX * 2];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b)swap(a, b);
	p[b] = a;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N * 2; i++) {
		p[i] = i;
	}
	while (M--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (!t) {
			merge(a, b);
			merge(a + N, b + N);
		}
		else {
			merge(a, b + N);
			merge(b, a + N);
		}
	}
	while (K--) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b) && find(a) != find(b + N))
			cout << "Unknown\n";
		else if (find(a) == find(a + N) || find(b) == find(b + N))
			cout << "Error\n";
		else if (find(a) == find(b))
			cout << "Friend\n";
		else if (find(a + N) == find(b))
			cout << "Enemy\n";
	}
}