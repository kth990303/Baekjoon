// 210821 #22939 쿠키크루 Gold V
// next_permutation 쓸 때는 sorting을 하자
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
int N, X, Y, Dx, Dy, t[4], res = INF;
vector<pi> v;
char job[4] = { 'J', 'C', 'B', 'W' };
char a[MAX][MAX];
int getDis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
void solve(int flag) {
	do {
		int x = X, y = Y, dis = 0;
		for (int i = 0; i < 3; i++) {
			dis += getDis(x, y, v[i].first, v[i].second);
			x = v[i].first, y = v[i].second;
		}
		dis += getDis(x, y, Dx, Dy);
		t[flag] = min(t[flag], dis);
	} while (next_permutation(all(v)));
}
void init(int flag) {
	v.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == job[flag])
				v.push_back({ j, i });
		}
	}
	sort(all(v));
	solve(flag);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'H') {
				Y = i; X = j;
			}
			else if (a[i][j] == '#') {
				Dy = i; Dx = j;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < 4; i++) {
		t[i] = INF;
		init(i);
		if (t[i] < res) {
			res = t[i];
			ans = i;
		}
	}
	if (!ans)
		cout << "Assassin\n";
	else if (ans == 1)
		cout << "Healer\n";
	else if (ans == 2)
		cout << "Mage\n";
	else
		cout << "Tanker\n";
}