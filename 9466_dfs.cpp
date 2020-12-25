// 201225 #9466 �� ������Ʈ Gold IV
// DFS (SCC �˰��� �̿� x Ǯ��)
#include <iostream>
#include <vector>
const int MAX = 100001;
using namespace std;
int N, cnt;
vector<int> v;
bool visit[MAX];
bool finished[MAX];
void dfs(int x) {
	visit[x] = true;
	if (visit[v[x]] && !finished[v[x]]) {
		// ������ó�� ���̴� �ڵ��̳�,
		// �ڱ� �ڽ��� �����̸� �ٽ� ÷�� ���� �̿�
		// ����Ŭ�� Ư¡
		for (int i = v[x]; i != x; i = v[i])
			cnt++;
		cnt++;
	}
	else if (!visit[v[x]])
		dfs(v[x]);
	finished[x] = true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		// �ʱ�ȭ �۾�
		v.clear();
		fill(visit, visit + MAX, false);
		fill(finished, finished + MAX, 0);
		cnt = 0;

		cin >> N;
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		cout << N - cnt << "\n";
	}
}