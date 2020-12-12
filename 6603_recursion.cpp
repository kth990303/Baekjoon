// 201212 #6603 로또 Silver II
// 재귀, 백트래킹 함수인자 2개 풀이
// 함수 인자가 2개인 경우는 for문이 없음.
#include <iostream>
#include <vector>
using namespace std;
int a[13], N;
vector<int> v;
void dfs(int num, int cnt) {
	// for문이 없는 대신, 배열 범위 체크하기
	if (cnt == N + 1)
		return;
	if (num == 6) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	// 포함하고
	v.push_back(a[cnt]);
	dfs(num + 1, cnt + 1);
	v.pop_back();
	// 포함 안하고
	dfs(num, cnt + 1);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N)
			break;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		dfs(0, 0);
		cout << "\n";
	}
}