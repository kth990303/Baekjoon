// 200918 #11969 Breed Counting Silver III
// 세그먼트트리? 1,2,3만 주어지므로 투포인터로 가능~
#include <iostream>
using namespace std;
const int MAX = 100001;
int N, M, a[MAX], pSum1[MAX], pSum2[MAX], pSum3[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		pSum1[i] = pSum1[i - 1];
		pSum2[i] = pSum2[i - 1];
		pSum3[i] = pSum3[i - 1];
		if (a[i] == 1) {
			pSum1[i]++;
		}
		else if (a[i] == 2) {
			pSum2[i]++;
		}
		else {
			pSum3[i]++;
		}
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		int p1 = pSum1[b] - pSum1[a - 1];
		int p2 = pSum2[b] - pSum2[a - 1];
		int p3 = pSum3[b] - pSum3[a - 1];
		cout << p1 << " " << p2 << " " << p3 << "\n";
	}
}