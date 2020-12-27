// 201227 #16456 하와와 대학생쨩 하와이로 가는 거시와요~ Silver I
// DP(BU) 시간복잡도: O(N)
// 일반항 나열 혹은 재귀적으로 접근
#include <iostream>
using namespace std;
const int MAX = 50001;
typedef long long ll;
ll N, d[MAX] = { 0,1,1,2 };
const ll MOD = 1e9 + 9;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 4; i <= N; i++) {
		// 두칸 점프 후 되돌아갔다가 가는 방법 + 한 칸 점프 방법
		d[i] = (d[i - 1] + d[i - 3]) % MOD;
	}
	cout << d[N] << "\n";
}