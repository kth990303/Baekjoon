// 211010 #1765 ´ß½Î¿ò ÆÀ Á¤ÇÏ±â Platinum V
// union_find
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 1011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, M, p[MAX];
vector<int> v, res[MAX];
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
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 0; i < M; i++) {
		char ch;
		int n1, n2;
		cin >> ch >> n1 >> n2;
		if (ch == 'E') {
			res[n1].push_back(n2);
			res[n2].push_back(n1);
		}
		else {
			merge(n1, n2);
		}
	}
	for (int i = 1; i <= N; i++) {
		int size = res[i].size();
		if (size < 2)
			continue;
		for (int j = 1; j < size; j++) {
			merge(find(res[i][0]), find(res[i][j]));
		}
	}
	for (int i = 1; i <= N; i++) {
		v.push_back(find(i));
	}
	sort(all(v));
	press(v);
	cout << v.size() << "\n";
}