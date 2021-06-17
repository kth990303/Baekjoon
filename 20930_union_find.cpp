// 210617 #20930 우주정거장 Platinum V
// line sweeping disjoint_set
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 200001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
struct Point {
	int x, y;
};
struct Space {
	Point p1, p2;
	int index;
};
vector<Space> v;
int N, Q, p[MAX];
bool cmpX(Space s1, Space s2) {
	if (s1.p1.x == s2.p1.x)
		return s1.p2.x < s2.p2.x;
	return s1.p1.x < s2.p1.x;
}
bool cmpY(Space s1, Space s2) {
	if (s1.p1.y == s2.p1.y)
		return s1.p2.y < s2.p2.y;
	return s1.p1.y < s2.p1.y;
}
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

	cin >> N >> Q;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].p1.x >> v[i].p1.y >> v[i].p2.x >> v[i].p2.y;
		if (v[i].p1.x > v[i].p2.x)
			swap(v[i].p1, v[i].p2);
		p[i] = i;
		v[i].index = i;
	}
	sort(all(v), cmpX); 
	int mx = v[0].p1.x;
	int Mx = v[0].p2.x;
	int idx = v[0].index;
	for (int i = 1; i < N; i++) {
		int m = v[i].p1.x;
		int M = v[i].p2.x;
		if (Mx < m) {
			idx = v[i].index;
			mx = v[i].p1.x;
			Mx = v[i].p2.x;
			continue;
		}
		Mx = v[i].p2.x;
		if (find(idx) != find(v[i].index))
			merge(idx, v[i].index);
	}
	for (int i = 0; i < N; i++) {
		if (v[i].p1.y > v[i].p2.y)
			swap(v[i].p1, v[i].p2);
	}
	sort(all(v), cmpY);
	int my = v[0].p1.y;
	int My = v[0].p2.y;
	idx = v[0].index;
	for (int i = 1; i < N; i++) {
		int m = v[i].p1.y;
		int M = v[i].p2.y;
		if (My < m) {
			idx = v[i].index;
			my = v[i].p1.y;
			My = v[i].p2.y;
			continue;
		}
		My = v[i].p2.y;
		if (find(idx) != find(v[i].index))
			merge(idx, v[i].index);
	}
	for (int i = 0; i < N; i++) {
		find(i);
	}
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (find(a)==find(b))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}