// 200913 #16397 Ż�� Gold IV
// �ִܰ�� �� ������������ ���� -> bfs�� ����
// �׸���� ���ٰ��� ����غôµ�, �Ұ����� �� ����.
// �����ϴ��� bfs�� �� ������
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
	queue<pair<int, int>> q;	// ���� ��, Ƚ��
	q.push({ cur, 0 });
	visit[cur] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		int len = to_string(x*2).length();
		q.pop();		
		// ������ ���������� ����
		if (x == G) {
			return cnt;
		}
		// ���� Ƚ���� �������ٰ� �ٷ� return -1 ���� ����
		if (cnt == T) {
			continue;
		}
		// �־��� query�� 2���̹Ƿ� �׳� if������
		if (!visit[x + 1]&&x+1<=99999) {
			visit[x + 1] = true;
			q.push({ x + 1, cnt + 1 });
		}
		int nx = x * 2 - pow(10, len - 1);
		// x�� 0�� ��, �׸��� x*2�� 99999 �������� �� üũ����
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