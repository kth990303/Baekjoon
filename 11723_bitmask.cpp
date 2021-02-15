// 210216 #11723 С§Че Silver V
// bitmasking (2^20)
// memory is only 4MB -> bitmask is good
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int S, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> M;
	while (M--) {
		string s;
		int x;
		cin >> s;
		if (s == "add") {
			cin >> x;
			S |= 1 << x;
		}
		else if (s == "remove") {
			cin >> x;
			S &= ~(1 << x);
		}
		else if (s == "check") {
			cin >> x;
			if (S & (1 << x))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			if(S & (1 << x))
				S &= ~(1 << x);
			else
				S |= 1 << x;
		}
		else if (s == "all") {
			S = (1 << 21) - 1;
		}
		else {
			S = 0;
		}
	}
}