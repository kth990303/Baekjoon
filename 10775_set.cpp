// 210407 #10775 °øÇ× Gold II
// 1. union_find 2. set, upper_bound
// this solution is second solution
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 100001;
int G, P, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> G >> P;
	set<int> s;
	for (int i = 1; i <= G; i++) {
		s.insert(i);
	}
	while (P--) {
		int n;
		cin >> n;
		auto it = s.upper_bound(n);
		if (it == s.begin())
			break;
		s.erase(*(--it));
		ans++;
	}
	cout << ans << "\n";
}