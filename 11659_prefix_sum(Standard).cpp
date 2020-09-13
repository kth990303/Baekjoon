// #11659 구간 합 구하기4 Silver III
// 수가 총 N개, 구간 합을 구하라는 쿼리 M개
// O(NM): 너무 오래걸림
// prefix_sum을 이용하면 O(M)
#include <iostream>
using namespace std;
int d[100001];
int s[100001];
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	// 누적합 배열을 따로 생성한다
	// s[1]=d[1], s[2]=s[1]+d[2], ...
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + d[i];
	}
	// query
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a - 1] << "\n";
	}
}