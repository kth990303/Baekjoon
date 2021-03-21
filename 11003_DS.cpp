// 210321 #11003 ÃÖ¼Ú°ª Ã£±â Platinum V
// priority_queue solution
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 5000001;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
int N, L, a[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		pq.push({ a[i], i });
		// index check
		while (pq.top().second <= i - L)
			pq.pop();
		cout << pq.top().first << " ";
	}
}