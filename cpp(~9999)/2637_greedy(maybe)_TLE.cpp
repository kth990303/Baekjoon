// greedy로 접근했다가 시간초과임과 위상정렬임을 깨달음
// 오기로 계속 만들어보긴 한 코드...
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[101];
int result[101];
int n, m;
vector<pair<int, int>> v[101];
void midToy(int min_a, int num, int ccnt) {
	for (int i = 0; i < v[num].size(); i++) {
		int k = v[num][i].first;
		int cnt = v[num][i].second * ccnt;
		if (k > min_a) {
			midToy(min_a, k, cnt);
		}
		else {
			result[k] += cnt;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int min_a = 100;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		min_a = min(a, min_a);
	}
	min_a--;
	midToy(min_a, n, 1);

	for (int i = 1; i <= min_a; i++) {
		cout << i << " " << result[i] << "\n";
	}
}