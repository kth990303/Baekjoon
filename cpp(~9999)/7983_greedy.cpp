// 201208 #7983 ���� �Ұž� Gold V
// ���� �׸���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, t;
		cin >> d >> t;
		v.push_back({ d,t });
	}
	// ���� ��������� ū �������
	sort(v.begin(), v.end(), cmp);
	// ���� ������ ������κ��� ����
	int ans = v[0].second;
	// ������ �������-�� ������ �ҿ�ð�
	// �� ���� ������ ������� �߿���
	// �� ���� ���� ����.
	// �ִ� ��ĥ�����̱� ������, ������ ���� ���ؾ� ��� �����ϱ�
	for (int i = 0; i < N-1; i++) {
		ans = min(ans - v[i].first, v[i + 1].second);
	}
	// ���� �ҿ�ð��� ������κ��� ������ ���� �� �ְ� �־����Ƿ�
	cout << ans - v[N - 1].first << "\n";
}