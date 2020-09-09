// 200909 #18138 �������� ���Ϸ����� ������ Platinum V
// �̺и�Ī�� Ȱ��
// double���� ����
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 201;
int N, M, d[MAX];
double w[MAX];	// ���� �ʺ�
bool used[MAX];
vector<int> v[MAX];
bool dfs(int x) {
	for (auto i : v[x]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs(d[i])) {
			d[i] = x;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= M; i++) {
		double val;
		cin >> val;
		for (int j = 1; j <= N; j++) {
			// �ʺ� �����ϸ� ��Ī �����ϰ�
			if (w[j] * 0.5 <= val && w[j] * 0.75 >= val) {
				v[j].push_back(i);
			}
			else if (w[j] <= val && w[j] * 1.25 >= val) {
				v[j].push_back(i);
			}
		}
	}
	int ans = 0;
	// �������� �̺и�Ī
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		if (dfs(i))
			ans++;
	}
	cout << ans << "\n";
}