// 201208 #7983 내일 할거야 Gold V
// 정렬 그리디
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, t;
		cin >> d >> t;
		v.push_back({ d,t });
	}
	// 과제 데드라인이 큰 순서대로
	sort(v.begin(), v.end(), cmp);
	// 가장 마지막 데드라인부터 시작
	int ans = v[0].second;
	// 마지막 데드라인-그 과제의 소요시간
	// 그 다음 마지막 데드라인 중에서
	// 더 빠른 것을 선택.
	// 최대 며칠동안이긴 하지만, 과제를 전부 다해야 놀수 있으니까
	for (int i = 0; i < N-1; i++) {
		ans = min(ans - v[i].first, v[i + 1].second);
	}
	// 과제 소요시간은 데드라인보다 빠르게 끝낼 수 있게 주어지므로
	cout << ans - v[N - 1].first << "\n";
}