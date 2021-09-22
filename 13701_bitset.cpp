// 210922 #13701 중복 제거 Gold III
// bitset practice
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
int N;
bitset<33554432> b;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	while (cin >> s) {
		int n = stoi(s);
		if (!b[n]) {
			cout << n << " ";
		}
		b[n] = 1;
	}
}