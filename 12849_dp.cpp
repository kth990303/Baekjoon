// 201219 #12849 본대 산책 Silver I
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9 + 7;
const int MAX = 100001;
int D, d[8][MAX];
vector<int> v[8];
void init() {
	// top-down 방식의 필수조건
	memset(d, -1, sizeof(d));
	// 경로를 init 해줌.
	v[0].push_back(1); v[1].push_back(0);
	v[0].push_back(2); v[2].push_back(0);
	v[1].push_back(2); v[2].push_back(1);
	v[1].push_back(3); v[3].push_back(1);
	v[2].push_back(3); v[3].push_back(2);
	v[2].push_back(4); v[4].push_back(2);
	v[3].push_back(4); v[4].push_back(3);
	v[3].push_back(5); v[5].push_back(3);
	v[4].push_back(5); v[5].push_back(4);
	v[4].push_back(6); v[6].push_back(4);
	v[5].push_back(7); v[7].push_back(5);
	v[6].push_back(7); v[7].push_back(6);
}
int dp(int cur, int time) {
	// time분일 때, cur로 갈 수 있는 경로의 수
	int& ret = d[cur][time];
	if (time == D) {
		// 정보관이라면 옳은 경로
		if (!cur)
			return 1;
		// 아니라면 옳지 않은 경로
		else
			return 0;
	}
	// 이미 경로의 수가 지정돼 있다면 (메모이제이션)
	if (ret != -1)
		return ret % INF;
	ret = 0;
	for (auto i : v[cur]) {
		ret += (dp(i, time + 1) % INF);
		ret %= INF;
	}
	return ret % INF;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	init();
	cin >> D;
	cout << dp(0, 0) << "\n";
}