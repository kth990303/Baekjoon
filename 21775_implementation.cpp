// 210524 #21775 °¡Èñ¿Í ÀÚ¿ø ³îÀÌ Gold IV
// map + implementation
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 500001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, T, a[MAX], t, p[MAX];
map<int, int> m;
vector<pair<string, pi>> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		cin >> a[i];
	}
	v.resize(T);
	for (int i = 0; i < T; i++) {
		cin >> v[i].second.first >> v[i].first;
		if (v[i].first != "next")
			cin >> v[i].second.second;
		else
			v[i].second.second = -1;
	}
	for (int i = 0; i < T; i++) {
		int turn = a[i];
		string s = v[t].first;
		int id = v[t].second.first;
		int val = v[t].second.second;
		if (p[turn]) {
			s = v[p[turn]].first;
			id = v[p[turn]].second.first;
			val = v[p[turn]].second.second;
			cout << id << "\n";
			if (m.find(val) == m.end()) {
				m[val] = turn;
				p[turn] = 0;
			}
		}
		else {
			cout << id << "\n";
			if (s == "acquire") {
				if (m.find(val) == m.end()) {
					m[val] = turn;
					p[turn] = 0;
				}
				else
					p[turn] = t;
			}
			else {
				m.erase(val);
			}
			t++;
		}
	}
}