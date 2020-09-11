// 200911 #16396 선 그리기 Bronze I
// O(N^2)의 풀이도 가능하나, 스위핑 연습 겸 O(N)으로
// 스위핑 이용
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10001;
const int INF = 1000000007;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	// 좌, 우
	pair<int, int> p[MAX];
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = { a,b };
	}
	// 왼쪽 좌표가 작은 순으로 정렬
	sort(p, p + N);
	int ans = 0;
	// 음수로 초기화
	// 이 때, 반드시 s=e여야 함! 
	// 첫번째 선분일 때의 기저 사례 때문
	int s = -INF, e = -INF;
	for (int i = 0; i < N; i++) {
		// 새로운 길이 선분 시작
		if (e < p[i].first) {
			ans += e - s;
			s = p[i].first;
			e = p[i].second;
		}
		else
			e = max(e, p[i].second);
	}
	// 마지막 선분을 더해야됨
	ans += e - s;
	cout << ans << "\n";
}