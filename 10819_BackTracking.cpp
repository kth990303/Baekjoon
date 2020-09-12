// 200912 #10819 ���̸� �ִ�� Silver II
// ��Ʈ��ŷ: ��� ������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 9;
int N, a[MAX], ans;
vector<int> v, d;
bool visit[MAX];
void dfs(int cnt) {
	if (cnt == N) {
		int sum = 0;
		for (int i = 1; i < v.size(); i++) {
			sum += abs(v[i] - v[i - 1]);
		}
		ans = max(sum, ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(a[i]);
			// ���⼭ 20 1 15 8 4 10���� �� ����
			dfs(cnt + 1);
			// ���⼭ 10 ���� for�� ���� �ٵ������� �� ����������
			// 4�� ����, for�� ������ ���� �� �� 10 ���鼭 dfs
			// ��, 20 1 15 8 10 4 ����
			// �̷��� ���������� �����鼭 ���� �ٲ�� ����
			// N�� M (1) ����
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	dfs(0);
	cout << ans << "\n";
}