// 210815 #19590 ºñµå¸Ç Gold II
// greedy, ad_hoc
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 100001;
ll N, M, num;
vector<ll> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	v.resize(N);
	bool flag = true;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		num += v[i];
		M = max(v[i], M);
	}
	if (num % 2)
		flag = false;
	if (N == 1)
		cout << v[0] << "\n";
	else if (N == 2)
		cout << max(v[0], v[1]) - min(v[0], v[1]) << "\n";
	else {
		// if M>num/2, cannot 0, 1
		if (2 * M > num)
			cout << 2 * M - num << "\n";
		else {
			if (flag)
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
	}
}