#include <iostream>
// 210321 #11003 ÃÖ¼Ú°ª Ã£±â Platinum V
// deque O(N + a) solution
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
const int MAX = 5000001;
typedef pair<int, int> pi;
deque<pi> dq;
int N, L;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		while (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > n)
			dq.pop_back();
		dq.push_back({ n, i });
		cout << dq.front().first << " ";
	}
}