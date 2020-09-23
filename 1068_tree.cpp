// 200923 #1068 Ʈ�� Silver I
// ��Ʈ���� 0�� �ƴ� ���� ����
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 51;
// Ʈ�� ����
vector<int> v[MAX];
int N, ans, num;	// num: ����� ���
bool visit[MAX];	// �湮 ����
vector<int> first;	// ��Ʈ ��� ����
void dfs(int cur) {
	visit[cur] = true;
	bool flag = true;	// ������������� ����
	for (auto i : v[cur]) {
		// ����� ����� ��� ����
		// �湮�� ���� ���
		if (!visit[i] && i!=num) {
			flag = false;	// �ڽĳ�尡 �����ϹǷ�
			visit[i] = true;
			dfs(i);
		}
	}
	if (flag && cur!=num)
		ans++;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p != -1) {
			v[p].push_back(i);
			v[i].push_back(p);
		}
		else
			first.push_back(i);
	}
	cin >> num;
	// �ڽ� ��� ������
	// �׷���, ���� �θ𿡼� num���� ���ϴ� ���� ����
	v[num].erase(v[num].begin(), v[num].end());
	for (auto i : first)
		dfs(i);
	cout << ans << "\n";
}