// 210417 #19543 던전 지도 Gold I
// two_pointers (because of only range can go destination)
// (N, M) is not (0, M)....
// O(MK)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MAX = 200001;
vector<string> block;
ll N, M, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	block.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> block[i];
	}
	string s;
	cin >> s;
	ll ans = 0;
	ll k = M - 2, l = M - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (i == N - 1) {
			for (ll j = M - 2; j >= 0; j--) {
				if (block[s[i] - 'A'][j] == 'U') {
					k = j;
					break;
				}
				k = -1;
			}
			ans += l - k;
			continue;
		}
		for (ll j = l; j > k; j--) {
			if (block[s[i] - 'A'][j] == 'U') {
				l = j;
				break;
			}
			l = k;
		}
		if (l <= k)
			break;
		for (ll j = k; j >= 0; j--) {
			if (block[s[i] - 'A'][j] == 'U') {
				k = j;
				break;
			}
			k = -1;
		}
		ans += l - k;
	}
	
	cout << ans << "\n";
}