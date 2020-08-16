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
	// max_first 지정 안해주면 ans.first 0 1 2 1과 같이
	// 맨 뒤가 더 작은 경우에서 틀림!
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		// 앞에 숫자보다 클 경우
		if (v.empty() || v.back() < num) {
			v.push_back(num);
			ans.push_back({ cnt, num });
			max_first = max(cnt, max_first);
			cnt++;
		}
		// 앞에 숫자보다 작을 경우 lower_bound (O(nlogn))
		else {
			auto it = lower_bound(v.begin(), v.end(), num);
			int pos = it - v.begin();
			*it = num;
			ans.push_back({ pos, num });
		}
	}
	// lis 배열 출력을 위한 스택 이용
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
