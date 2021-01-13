// 210113 #11509 풍선 맞추기 Silver I
// Greedy
#include <iostream>
using namespace std;
const int MAX = 1000001;
int N, cnt[MAX], ans;
// 이전 풍선의 개수들을 저장
// 화살이 왼쪽에서 오른쪽으로 가므로, 주어진 순서대로 쿼리처리하면 됨
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (cnt[num + 1])
			cnt[num + 1]--;
		else
			ans++;
		cnt[num]++;
	}
	
	cout << ans << "\n";
}