// 210102 #14226 이모티콘 Gold V
// similar as #16953: Silver I
// queue (like bfs)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1001;
int S;
// variables depend on the answers
// ex) copy, num -> two dimensional array
// Need to check the range of array
bool visit[MAX * 2][MAX];
int bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, { 1, 0 } });
	visit[1][0] = true;
	while (!q.empty()) {
		int time = q.front().first;
		int n = q.front().second.first;
		int copy = q.front().second.second;
		q.pop();
		if (n == S)
			return time;
		if (n > 1 && !visit[n-1][copy]) {
			visit[n - 1][copy] = true;
			q.push({ time + 1, { n - 1, copy } });
		}
		if (n+copy <= 1000 && !visit[n + copy][copy]) {
			visit[n + copy][copy] = true;
			q.push({ time + 1, { n + copy, copy } });
		}
		q.push({ time + 1,{ n, n } });
		visit[n][n] = true;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> S;
	cout << bfs() << "\n";
}