// 210414 
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.begin(), v.end()
using namespace std;
const int MAX = 200001;
typedef pair<int, pair<int, int>> pii;
int N, sum, ans[MAX], c[MAX];
vector<pii> v;
bool cmp(pii p1, pii p2) {
	// color ASC (26% WA)
	if (p1.second.second == p2.second.second)
		return p1.second.first < p2.second.first;
	return p1.second.second < p2.second.second;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int color, size;
		cin >> color >> size;
		v.push_back({ i, {color, size} });
	}
	sort(all(v), cmp);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		int idx = v[i].first;
		int color = v[i].second.first;
		int size = v[i].second.second;
		// if same size (4% WA)
		if (i && size == v[i - 1].second.second) {
			tmp += size;
			sum -= size;
		}
		else {
			sum += tmp;
			tmp = 0;
		}
		ans[idx] += sum - c[color];
		sum += size;
		c[color] += size;
		// if same color, size
		// then same answer (18%? WA)
		if (i && color == v[i - 1].second.first && size == v[i - 1].second.second)
			ans[idx] = ans[v[i - 1].first];
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}