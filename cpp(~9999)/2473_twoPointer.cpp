// 200902 #2473 세 용액 Gold IV
// #2467 용액의 업그레이드 버전
// 투포인터
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;	// 30억 넘는 걸로 잡아야됨
int N;
ll ans1, ans2, ans3;
vector<ll> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll sum = INF;
	// 1번째: 맨왼쪽
	for (int i = 0; i < N - 2; i++) {
		int s = i + 1;	// 2번째: 1번째보다 큰거부터
		int e = N - 1;	// 3번째: 맨 끝에서부터
		while (1) {
			// 교차 탐색 방지
			if (s == e)
				break;
			if (abs(v[i] + v[s] + v[e]) < sum) {
				ans1 = v[i];
				ans2 = v[s];
				ans3 = v[e];
				sum = (ll)abs(v[i] + v[s] + v[e]);
			}
			// 24번째 줄에 sort를 해줬으므로
			if (v[i] + v[s] + v[e] > 0)
				e--;
			else
				s++;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << "\n";
}