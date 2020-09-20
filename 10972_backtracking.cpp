// 200921 #10972 다음 순열 Silver III
// 대놓고 next_permutation
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 10001;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	do {
		// 다음 순열로 증가시키기 위해
		if (!cnt) {
			cnt++;
			continue;
		}
		// (1) cnt=0일 때 마지막이었으면
		// 이부분은 작동하지 못하고 끝남
		if (cnt == 1) {
			for (auto i : v)
				cout << i << " ";
			cnt++;
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
	// (1)의 경우, -1 출력하고 끝
	if (cnt == 1)
		cout << -1 << "\n";
}