// 200902 #11266 ������ Platinum V
// crocus�� ��α� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int d[MAX], V, E, id;
vector<int> v[MAX];
vector<int> answer;	// ������ ���
bool ans[MAX];	// ������ ����
int dfs(int x, bool isRoot) {
	d[x] = ++id;
	int ret = d[x];
	int child = 0;
	for (auto i : v[x]) {
		// Ž���� �����̶��
		if (d[i]) {
			// �� ���� Ž���� ������ ret����
			ret = min(ret, d[i]);
			continue;
		}
		child++;
		int prev = dfs(i, false);
		// ��Ʈ ��尡 �ƴ� ���
		// �ڽ� ������ �ڽź��� �� ���� �湮��ȣ�� ���� ���� �����ϴٸ� ������
		if (!isRoot && prev >= d[x]) {
			ans[x] = true;
		}
		ret = min(ret, prev);
	}
	// ��Ʈ ����� ��� �ڽ� ���� 2�� �̻��̸� ������
	if (isRoot && child>=2) {
		ans[x]=true;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (!d[i])
			dfs(i, true);
	}
	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		if (ans[i])
			answer.push_back(i);
	}
	cout << answer.size() << "\n";
	for (auto i : answer)
		cout << i << " ";
	cout << "\n";
}