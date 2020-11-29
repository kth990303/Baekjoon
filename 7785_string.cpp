// #7785 ȸ�翡 �ִ� ��� Silver V
// ȸ�翡 �ִ� ������� ������ �� �� ��� ó�������� ����
// �ִ� ������� for������ �� �ѷ����� O(N^2)���� tle���״�
// map�� �̿��ϵ�, ���������� �����ϵ� ����.
// �� Ǯ�̴� map�� �̿��ߴ�.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	map<string, int> m;
	vector<string> ans;
	for (int i = 0; i < N; i++) {
		string s, flag;
		cin >> s >> flag;
		if (flag == "enter")
			m[s]++;
		else
			m[s]--;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if ((*it).second > 0)
			ans.push_back((*it).first);
	}
	sort(ans.begin(), ans.end(), greater<>());
	// sort(ans.end(), ans.begin());
	// sort(ans.rbegin(), ans.rend());
	for (auto i : ans)
		cout << i << "\n";
}