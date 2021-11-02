// 201207 #9376 ������� ���� Silver III
// MST�̳�, ����ġ�� ���� dfs�ε� ���� ����... �ϳ�,
// ��� �� N-1�� ���̾ print(n-1)�� ����.
#include <iostream>
#include <vector>
using namespace std;
int N, M, ans;
const int MAX = 10001;
vector<int> v[MAX];
int p[1001];	// mst�� �ϱ� ���� ������Ʈ ��ǥ��ȣ �迭
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

	int t;
	cin >> t;
	while (t--) {
		for (auto& i : v)
			i.clear();
		ans = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			p[i] = i;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (merge(i, j))
					ans++;
			}
		}
		cout << ans << "\n";
	}
}