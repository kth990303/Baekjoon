// 210620 #3649 로봇 프로젝트 Gold IV
// two_pointers O(N)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int X, N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> X >> N;
		if (cin.eof())
			break;
		X *= 1e7;
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		sort(all(v));
		int s = 0, e = N - 1;
		while (s < e) {
			if (v[s] + v[e] == X) {
				cout << "yes " << v[s] << " " << v[e] << "\n";
				break;
			}
			if (v[s] + v[e] > X)
				e--;
			else
				s++;
		}
		if (s >= e)
			cout << "danger\n";
	}
}