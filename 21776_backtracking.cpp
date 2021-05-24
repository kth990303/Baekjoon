// 210524 #21776 °¡Èñ¿Í ÀÐ±â ¾²±â ³îÀÌ Gold III
// backtracking + string parsing
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
const int MAX = 11;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, C, pos[MAX];
vector<int> v[MAX], turn;
vector<pair<string, char>> card[MAX];
vector<string> ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		while (n--) {
			turn.push_back(i);
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	cin.ignore();
	for (int i = 1; i <= C; i++) {
		string s;
		getline(cin, s);
		int n = 0;
		while (6 * n + 4 < s.length()) {
			string tmp = s.substr(6 * n, 3);
			char ch = s[6 * n + 4];
			card[i].push_back({ tmp, ch });
			n++;
		}
	}
	sort(all(turn));
	do {
		fill(pos, pos + MAX, 0);
		bool flag = false;
		string s;
		for (auto i : turn) {
			int idx = v[i][pos[i]];
			for (auto j : card[idx]) {
				string ch = j.first;
				char val = j.second;
				if (ch == "ADD") {
					s += val;
				}
				else {
					if (s.length() > (int)(val - '0'))
						s.erase((int)(val - '0'), 1);
					else {
						s = "ERROR";
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
			pos[i]++;
		}
		if (s.empty())
			s = "EMPTY";
		ans.push_back(s);
	} while (next_permutation(all(turn)));
	sort(all(ans));
	press(ans);
	for (auto i : ans) {
		cout << i << "\n";
	}
}