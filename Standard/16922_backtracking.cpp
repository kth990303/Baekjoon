// 200915 #16922 로마 숫자 만들기 Silver III
// 백트래킹: 중복조합, 단 N과 M(4) 문제와 다르게 N범위가 20.
// 4^20을 겪고 싶지 않다면 그 때와 방법을 바꿔라
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
	// 이 부분이 달라짐.
	// i=0부터 할 필요가 없음. 현재 cur을 인자로 추가함으로써
	// 백트래킹하고 어디서부터 다시 시작해야될 지 알려줌
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