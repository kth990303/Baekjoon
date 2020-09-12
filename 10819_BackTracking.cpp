// 200912 #10819 차이를 최대로 Silver II
// 백트래킹: 재귀 연습용
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
			// 여기서 20 1 15 8 4 10까지 다 끝냄
			dfs(cnt + 1);
			// 여기서 10 빼고 for문 루프 다돌았으니 또 빠져나오고
			// 4도 빼고, for문 마지막 루프 돌 때 10 돌면서 dfs
			// 즉, 20 1 15 8 10 4 실행
			// 이렇게 끝에서부터 빠지면서 순서 바뀌고 실행
			// N과 M (1) 문제
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