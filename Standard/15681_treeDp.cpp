// 201210 #15681 Ʈ���� ���� Gold V
// Ʈ�������� dp
// �׷��������� dp�� �ڽŰ����� d �迭�� ����������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
bool visit[MAX];
int d[MAX];	// ��� �޸������̼�
int N, R, Q;
int dfs(int x) {
	if (visit[x])
		return d[x];	// �޸������̼� Ȱ��
	visit[x] = true;
	for (auto i : v[x]) {
		if (!visit[i]) {
			// ���⿡ visit ó�����ָ�, 14��° ����
			// if������ �ٷ� return�ع���.
			d[x] = d[x] + dfs(i);
		}
	}
	return d[x];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> R >> Q;
	fill(d, d + MAX, 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// �޸������̼��� �̸� �س�����
	dfs(R);
	// �������� ����� �ʿ� ���� �迭���� ���� ã���� ��.
	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << d[q] << "\n";
	}
}