// 200923 #4803 Ʈ�� Gold IV
// Ʈ���� �ƴ� ���� ó��
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, cnt;
const int MAX = 501;
vector<int> v[MAX];
bool visit[MAX];
int pre[MAX];
// dfs�� �ߴ��� �ڲ� Ʋ�� (200923 ����)
// �׷��� bfs�� �ߴ��� ����(...)
bool bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visit[cur] = true;
	bool flag = true;	// Ʈ�������� ����
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : v[x]) {
			if (!visit[i]) {
				visit[i] = true;
				pre[i] = x;
				q.push(i);
			}
			// ����Ŭ�� �����ϴ� ���
			// �ᱹ �ڽ��� �θ� �ΰ��� ��� (��Ʈ�� �ϳ��̹Ƿ�)
			else if (i != pre[x])
				flag = false;
		}
	}
	return flag;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int tc = 1;
	while (cin >> N >> M) {
		if (!N && !M)
			break;
		// �ʱ�ȭ
		for (auto& i : v)
			i.clear();
		fill(visit, visit + MAX, false);
		// Ʈ�� �ƴ� ��찡 �����ϹǷ�
		// �θ� ��带 ��� �迭�� �ʿ���
		fill(pre, pre + MAX, -1);
		cnt = 0;
		// Ʈ�� ����
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		// Ʈ�� ��ȸ
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				if (bfs(i))
					cnt++;
			}
		}
		// ���� �����
		if (!cnt)
			cout << "Case " << tc << ": No trees.\n";
		else if (cnt == 1)
			cout << "Case " << tc << ": There is one tree.\n";
		else
			cout << "Case " << tc << ": A forest of " << cnt << " trees.\n";
		tc++;
	}
}