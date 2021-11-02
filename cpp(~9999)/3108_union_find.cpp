// 210914 #3108 ·Î°í Gold III
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
const int MAX = 1001;
int N, p[MAX], ans, cnt[MAX];
struct Square {
	int x1, x2, y1, y2;
};
Square s[MAX];
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
bool con(Square s1, Square s2) {
	if (s1.x1 < s2.x1 && s2.x2 < s1.x2 &&
		s1.y1 < s2.y1 && s2.y2 < s1.y2)
		return false;
	if (s2.x1 < s1.x1 && s1.x2 < s2.x2 &&
		s2.y1 < s1.y1 && s1.y2 < s2.y2)
		return false;
	if (s2.x2 < s1.x1 || s1.x2 < s2.x1 ||
		s1.y2 < s2.y1 || s2.y2 < s1.y1)
		return false;
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	s[0].x1 = 0, s[0].x2 = 0, s[0].y1 = 0, s[0].y2 = 0;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
		cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
		if (con(s[0], s[i]))
			merge(0, i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (con(s[i], s[j]))
				merge(i, j);
		}
	}
	for (int i = 1; i <= N; i++) {
		cnt[find(i)]++;
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i])
			ans++;
	}
	cout << ans << "\n";
}