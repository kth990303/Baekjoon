// 201219 #12849 ���� ��å Silver I
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9 + 7;
const int MAX = 100001;
int D, d[8][MAX];
vector<int> v[8];
void init() {
	// top-down ����� �ʼ�����
	memset(d, -1, sizeof(d));
	// ��θ� init ����.
	v[0].push_back(1); v[1].push_back(0);
	v[0].push_back(2); v[2].push_back(0);
	v[1].push_back(2); v[2].push_back(1);
	v[1].push_back(3); v[3].push_back(1);
	v[2].push_back(3); v[3].push_back(2);
	v[2].push_back(4); v[4].push_back(2);
	v[3].push_back(4); v[4].push_back(3);
	v[3].push_back(5); v[5].push_back(3);
	v[4].push_back(5); v[5].push_back(4);
	v[4].push_back(6); v[6].push_back(4);
	v[5].push_back(7); v[7].push_back(5);
	v[6].push_back(7); v[7].push_back(6);
}
int dp(int cur, int time) {
	// time���� ��, cur�� �� �� �ִ� ����� ��
	int& ret = d[cur][time];
	if (time == D) {
		// �������̶�� ���� ���
		if (!cur)
			return 1;
		// �ƴ϶�� ���� ���� ���
		else
			return 0;
	}
	// �̹� ����� ���� ������ �ִٸ� (�޸������̼�)
	if (ret != -1)
		return ret % INF;
	ret = 0;
	for (auto i : v[cur]) {
		ret += (dp(i, time + 1) % INF);
		ret %= INF;
	}
	return ret % INF;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	init();
	cin >> D;
	cout << dp(0, 0) << "\n";
}