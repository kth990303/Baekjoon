// 210922 #13701 �ߺ����� Gold III
// bitmasking optimization
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
#include <bitset>
#include <sstream>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 5000001;
const int INF = 0x3f3f3f3f;
// int: 32bit -> 2^20 cnts
int d[1 << 20];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	while (cin >> s) {
		int n = stoi(s);
		int a = n / 32, b = n % 32;
		if (!(d[a] & (1<<b))) {
			cout << n << " ";
			d[a] |= (1 << b);
		}
	}
}