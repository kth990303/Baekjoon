// 200817 UCPC 2020 예선 D번 #19535 Gold III
// ㄷ tree 구하는게 어려움
// ㅈ tree 발상도 쉽지는 않음... 이게 뭐가 easy야 ㅁㅊ;;;
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> v[300001];
bool visit[300001];
ll d, g;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	// tree init
	for (int i = 0; i < n - 1; i++) {
		int a, b, j = 0;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// count g
	for (int i = 1; i <= n; i++) {
		if (v[i].size() >= 3) {
			g += (v[i].size() * (v[i].size() - 1) * (v[i].size() - 2)) / 6;
		}
	}
	// count d
	for (int i = 1; i <= n; i++) {
		for (auto j : v[i]) {
			int k = v[i].size() * v[j].size();
			if (k >= 4) {
				d += (ll)(v[i].size() - 1) * (v[j].size() - 1);
			}
		}
	}
	d /= 2;
	// result
	if (d > g * 3)
		cout << "D\n";
	else if (d < g * 3)
		cout << "G\n";
	else
		cout << "DUDUDUNGA\n";
}