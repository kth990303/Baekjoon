// 210211 #1088 ÄÉÀÌÅ© Platinum II
// Greedy : if Big, cut it in half!
// not half -> min cake is smaller...
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<pair<double, double>, int> pii;
const int MAX = 51;
int N, M;
double a[MAX];
double ans = 2e9 + 7, minN = 2e9 + 7;
priority_queue<pii> pq;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(15);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		minN = min(a[i], minN);
		pq.push({ {a[i], 1}, i });
	}
	cin >> M;
	++M;
	while (M--) {
		double maxN = pq.top().first.first;
		double time = pq.top().first.second;
		int idx = pq.top().second;
		pq.pop();
		ans = min(ans, maxN - minN);
		++time;
		pq.push({ {a[idx] / time, time}, idx });
		minN = min(minN, a[idx]/time);
	}
	cout << ans << "\n";
}