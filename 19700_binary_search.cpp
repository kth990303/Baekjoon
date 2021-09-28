// 210928 #19700 ¼ö¾÷ Gold I
// greedy, binary_search
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 500011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
int N, ans;
priority_queue<pi> pq;
vector<int> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int h, n;
		cin >> h >> n;
		pq.push({ h, n });
	}
	while (!pq.empty()) {
		int n = pq.top().second;
		pq.pop();
		int idx = upper_bound(all(v), n, greater<int>()) - v.begin();
		if (idx == v.size())
			v.push_back(1);
		else
			v[idx]++;
	}
	cout << v.size() << "\n";
}