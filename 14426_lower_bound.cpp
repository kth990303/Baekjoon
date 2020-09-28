// ruz님 풀이 참고
// 보자마자 진짜 머리 좋으신 분이구나 싶었음
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, ans;
vector<string> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	while (N--) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	while (M--) {
		string s;
		cin >> s;
		auto it = lower_bound(v.begin(), v.end(), s);
		string tmp = it->substr(0, s.size());
		if (tmp == s)
			ans++;
	}
	cout << ans << "\n";
}