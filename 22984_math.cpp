// 210830 #22984 ¹ÝÂ¦¹ÝÂ¦2 Silver I
// math:probability theory
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 100001;
double N, ans, a[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cout << fixed;
	cout.precision(16);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		ans += a[i];
		if (i)
			ans += a[i - 1] * (1 - a[i]) + a[i] * (1 - a[i - 1]);
	}
	cout << ans << "\n";
}