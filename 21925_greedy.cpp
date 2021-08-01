// 210801 #21925 Â¦¼öÆÓ¸°µå·Ò Gold III
// greedy, stack
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 5001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], ans;
vector<int> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		if (v.size() > N / 2) {
			cout << -1 << "\n";
			return 0;
		}
		if (v.empty() || v.back() != a[i])
			v.push_back(a[i]);
		else if (v.back() == a[i]) {
			bool flag = true;
			for (int j = 0; i + j < N; j++) {
				if ((int)v.size() - 1 - j < 0)
					break;
				if (i+j>=N || v[v.size() - 1 - j] != a[i + j]) {
					flag = false;
					break;
				}			
			}
			if (flag) {
				i += v.size() - 1;
				v.clear();
				ans++;
			}
			else
				v.push_back(a[i]);
		}
	}
	cout << (v.size() ? -1 : ans) << "\n";
}