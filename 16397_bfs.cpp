// 200913 #16397 탈출 Gold IV
// 최단경로 및 쿼리느낌나는 문제 -> bfs로 접근
// 그리디로 접근가능 고려해봤는데, 불가능할 거 같음.
// 가능하더라도 bfs가 더 나을듯
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
const int MAX = 100000;
int N, T, G, ans;
bool visit[MAX];
int bfs(int cur) {
	queue<pair<int, int>> q;	// 현재 수, 횟수
	q.push({ cur, 0 });
	visit[cur] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		int len = to_string(x*2).length();
		q.pop();		
		// 목적에 도달했으면 리턴
		if (x == G) {
			return cnt;
		}
		// 제한 횟수와 같아졌다고 바로 return -1 하지 말자
		if (cnt == T) {
			continue;
		}
		// 주어진 query는 2개이므로 그냥 if문으로
		if (!visit[x + 1]&&x+1<=99999) {
			visit[x + 1] = true;
			q.push({ x + 1, cnt + 1 });
		}
		int nx = x * 2 - pow(10, len - 1);
		// x가 0일 때, 그리고 x*2가 99999 이하인지 잘 체크하자
		if (x && !visit[nx] && x*2<=99999) {
			visit[nx] = true;
			q.push({ nx, cnt + 1 });
		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T >> G;
	ans = bfs(N);
	if (ans == -1) {
		cout << "ANG" << "\n";
	}
	else
		cout << ans << "\n";
}