// 201212 #11729 하노이 탑 이동순서 Silver II
// 재귀 문제를 풀 때의 습관
// 재귀(Standard)를 풀 때는 큰 틀만 짜고 나머지는 컴퓨터에 맡기기
// 재귀 호출되는 과정을 하나씩 따라가지 말자
#include <iostream>
using namespace std;
int N;
// d[5]=d[4]+5번째 원판+나머지 4개의 원판
// d[4]는 재귀가 알아서 해주겠지 라는 마인드로.
void solve(int h, int cur, int tmp, int next) {
	if (!h)
		return;
	// 전반부
	solve(h - 1, cur, next, tmp);
	// 가운데 (맨 아래 원판)
	cout << cur << " " << next << "\n";
	// 후반부
	solve(h - 1, tmp, cur, next);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	// bitmask
	cout << (1 << N) - 1 << "\n";
	solve(N, 1, 2, 3);
}