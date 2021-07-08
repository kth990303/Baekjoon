// 210708 #17299 오등큰수 Gold III
// use stack + cnt(or map)
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, K, a[MAX], cnt[MAX], d[MAX];
vector<int> v;
vector<pi> st;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	fill(d, d + N, -1);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i < N; i++) {
		v[i] = cnt[a[i]];
		while (!st.empty() && st.back().second < v[i]) {
			d[st.back().first] = a[i];
			st.pop_back();
		}
		st.push_back({ i, v[i] });
	}
	for (int i = 0; i < N; i++) {
		cout << d[i] << " ";
	}
}