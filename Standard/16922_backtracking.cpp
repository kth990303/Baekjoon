// 200915 #16922 �θ� ���� ����� Silver III
// ��Ʈ��ŷ: �ߺ�����, �� N�� M(4) ������ �ٸ��� N������ 20.
// 4^20�� �ް� ���� �ʴٸ� �� ���� ����� �ٲ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
bool used[MAX];
int N, a[4] = { 1,5,10,50 };
vector<int> v;
void dfs(int cnt, int cur) {
	if (cnt == N) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		used[sum] = true;
		return;
	}
	// �� �κ��� �޶���.
	// i=0���� �� �ʿ䰡 ����. ���� cur�� ���ڷ� �߰������ν�
	// ��Ʈ��ŷ�ϰ� ��𼭺��� �ٽ� �����ؾߵ� �� �˷���
	for (int i = cur; i < 4; i++) {
		v.push_back(a[i]);
		dfs(cnt + 1, i);
		v.pop_back();
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	dfs(0,0);
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		if (used[i])
			cnt++;
	}
	cout << cnt << "\n";
}