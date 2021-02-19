// 210219 #16724 피리 부는 사나이 Gold II
// union-find
// it's not simply count components
/*
3 8
RRRLRRRD
RRRRURLD
RRRLULLL
ans : 4
wrong: 5 (if only count components)
*/
// check cycle or union-find
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1001;
int N, M, ans, p[MAX * MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
bool visit[MAX * MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
		}
	}
	for (int i = 0; i < N * M; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n1 = i * M + j;
			int n2;
			if (a[i][j] == 'U') {
				n2 = (i + dy[0]) * M + (j + dx[0]);
			}
			if (a[i][j] == 'D') {
				n2 = (i + dy[1]) * M + (j + dx[1]);
			}
			if (a[i][j] == 'L') {
				n2 = (i + dy[2]) * M + (j + dx[2]);
			}
			if (a[i][j] == 'R') {
				n2 = (i + dy[3]) * M + (j + dx[3]);
			}
			merge(n1, n2);
		}
	}
	// next, last finally do union-find
	// and count unions -> visit[find(i)] 
	for (int i = 0; i < N * M; i++) {
		if (!visit[find(i)]) {
			visit[find(i)] = true;
			ans++;
		}
	}
	cout << ans << "\n";
}