// 201225 #9466 �� ������Ʈ Gold IV
// topology sort Ǯ�� (dfs, scc �˰��� Ǯ�� ���� ����)
// dfs: 584ms / topology: 560ms / scc: 1520ms
// O(N) : O(V+E)
// DAG �̹Ƿ� �������� ���� ����
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int MAX = 100001;
using namespace std;
vector<int> v;
int in[MAX];	// ���� ������ �����ϱ������ ����
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		fill(in, in + MAX, 0);

		int N, cnt = 0;
		cin >> N;
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
			// ���� ����
			in[v[i]]++;
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1; i <= N; i++) {
			// ������
			if (!in[i]) {
				pq.push(i);
				cnt++;
			}
		}
		// priority_queue�̵� queue�̵� ������ �߿��� ���� �ƴϴ�.
		// �ٸ�, queue���� ������ ������ �־�� �Ѵ�. (indegree ����)
		while (!pq.empty()) {
			int t = pq.top();
			pq.pop();
			// ������ ���ʰ� �� ������ ���ҽ�Ű��, ������ 0�� ����
			if (--in[v[t]] == 0) {
				// ���� ���� ����
				pq.push(v[t]);
				// ���� ���� ���۵Ǵ� ��� = ����Ŭ�� �� �̷�� ���
				// ���������� DAG������ ���� ����!
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}