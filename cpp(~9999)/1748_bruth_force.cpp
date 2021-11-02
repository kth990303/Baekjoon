//210110 #1748 수 이어쓰기1 Silver III
// Bruth-force, Why AC? if AC->Bronze III ~ Bronze II
#include <iostream>
#include <cmath>
using namespace std;
int N, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i < 10)
            ans++;
        else if (i >= 10 && i < 100)
            ans += 2;
        else if (i >= 100 && i < 1000)
            ans += 3;
        else if (i >= 1000 && i < 10000)
            ans += 4;
        else if (i >= 10000 && i < 100000)
            ans += 5;
        else if (i >= 100000 && i < 1000000)
            ans += 6;
        else if (i >= 1000000 && i < 10000000)
            ans += 7;
        else if (i >= 10000000 && i < 100000000)
            ans += 8;
        else if (i >= 100000000)
            ans += 9;
    }
	cout << ans << "\n";
}