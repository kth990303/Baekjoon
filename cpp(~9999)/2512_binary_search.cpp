// 201227 #2512 예산 Silver III
// Binary_search O(NlgM)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int N, M, a[MAX];
int solve(int s, int e) {
	// 이분 탐색 이용: O(lgM)
	while (s <= e) {
		// s=e일 때 탐색하면 c++ 버림에 따른
		// mid값 차이에 의한 의도치 않은 버그도 잡을 수 있음.
		int mid = (s + e) / 2;
		int sum = 0;
		// O(NlgM)인 이유
		for (int i = 0; i < N; i++) {
			sum += min(a[i], mid);
		}
		if (sum <= M)
			s = mid + 1;
		else
			e = mid - 1;
	}
	// 같을 경우 s를 1 증가시켰으므로 리턴값은 s-1
	return s - 1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int h = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		h = max(h, a[i]);
	}
	cin >> M;
	// M에 따라 s는 최소원소보다 작을 수 있으므로
	// s는 0부터 e는 나올 수 있는 최대로.
	cout << solve(0, h) << "\n";
}