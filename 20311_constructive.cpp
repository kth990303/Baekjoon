// 210908 #20311 화학실험 Gold V
// constructive, greedy
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 300001;
int N, K, a[MAX], b[MAX], ans[MAX];
vector<pi> v;
bool cmp(pi p1, pi p2) {
	return p1.first > p2.first;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	if (K == 1 && N == 1) {
		cout << 1 << "\n";
		return 0;
	}
	else if (K == 1) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 1; i <= K; i++){
		cin >> a[i];
		if (a[i] > (N + 1) / 2) {
			cout << -1 << "\n";
			return 0;
		}
		v.push_back({ a[i], i });
	}
	sort(all(v), cmp);
	int i = 0, j = 0;
	while (i < K) {
		while (v[i].first) {
			b[j++] = v[i].second;
			v[i].first--;
		}
		i++;
	}
	if (N % 2) {
		int j = 0;
		for (int i = 0; i < N; i += 2, j++) {
			ans[i] = b[j];
		}
		for (int i = 1; i < N; i += 2, j++) {
			ans[i] = b[j];
		}
	}
	else {
		int j = 0;
		for (int i = 1; i < N; i += 2, j++) {
			ans[i] = b[j];
		}
		for (int i = 0; i < N; i += 2, j++) {
			ans[i] = b[j];
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}