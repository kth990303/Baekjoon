// 210606 #20164 È¦¼ö È¦¸¯ È£¼®
// dfs + string + recursion
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
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
string N;
int dfs1(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		if (((int)(s[i] - '0')) % 2)
			ret++;
	}
	if (s.length() == 1)
		return ret;
	else if (s.length() == 2) {
		ret += dfs1(to_string((int)(s[0] - '0') 
			+ (int)(s[1] - '0')));
	}
	else {
		int p1, p2, tmp = INF;
		for (int i = 1; i < s.length() - 1; i++) {
			for (int j = i + 1; j < s.length(); j++) {
				p1 = i; p2 = j;
				int num = stoi(string(s.begin(), s.begin() + p1)) +
					stoi(string(s.begin() + p1, s.begin() + p2)) +
					stoi(string(s.begin() + p2, s.end()));
				tmp = min(tmp, dfs1(to_string(num)));
			}
		}
		ret += tmp;
	}
	return ret;
}
int dfs2(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		if (((int)(s[i] - '0')) % 2)
			ret++;
	}
	if (s.length() == 1)
		return ret;
	else if (s.length() == 2) {
		ret += dfs2(to_string((int)(s[0] - '0')
			+ (int)(s[1] - '0')));
	}
	else {
		int p1, p2, tmp = 0;
		for (int i = 1; i < s.length() - 1; i++) {
			for (int j = i + 1; j < s.length(); j++) {
				p1 = i; p2 = j;
				int num = stoi(string(s.begin(), s.begin()+p1)) +
					stoi(string(s.begin()+p1, s.begin()+p2)) +
					stoi(string(s.begin()+p2, s.end()));
				tmp = max(tmp, dfs2(to_string(num)));
			}
		}
		ret += tmp;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	cout << dfs1(N) << " " << dfs2(N) << "\n";
}