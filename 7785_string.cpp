// #7785 회사에 있는 사람 Silver V
// 회사에 있는 사람들을 나가게 할 때 어떻게 처리할지가 관건
// 있는 사람들을 for문으로 쭉 둘러보면 O(N^2)으로 tle일테니
// map을 이용하든, 수학적으로 접근하든 하자.
// 이 풀이는 map을 이용했다.
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