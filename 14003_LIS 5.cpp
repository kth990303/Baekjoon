// 200816 14003 LIS 5 O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int a[1000001];
vector<int> v;
vector<pair<int, int>> ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, cnt = 0;
	cin >> n;
	int max_first = 0;
	// LIS Algorithm
	// max_first ���� �����ָ� ans.first 0 1 2 1�� ����
	// �� �ڰ� �� ���� ��쿡�� Ʋ��!
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		// �տ� ���ں��� Ŭ ���
		if (v.empty() || v.back() < num) {
			v.push_back(num);
			ans.push_back({ cnt, num });
			max_first = max(cnt, max_first);
			cnt++;
		}
		// �տ� ���ں��� ���� ��� lower_bound (O(nlogn))
		else {
			auto it = lower_bound(v.begin(), v.end(), num);
			int pos = it - v.begin();
			*it = num;
			ans.push_back({ pos, num });
		}
	}
	// lis �迭 ����� ���� ���� �̿�
	int num = max_first;
	stack<int> s;
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (num == ans[i].first) {
			s.push(ans[i].second);
			num--;
		}
	}
	int size = s.size();
	cout << size << "\n";
	for (int i = 0; i < size; i++) {
		cout << s.top() << " ";
		s.pop();
	}

}
