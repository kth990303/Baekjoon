// 200926 #2108 통계학 Silver IV
// 반올림, 최빈값 조건 등 까다로운 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 8001;
int used[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> v(N);
	double sum = 0;
	int max_cnt = 0;	// 최빈값 개수
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
		used[v[i] + 4000]++;
		max_cnt = max(max_cnt, used[v[i] + 4000]);
	}
	sort(v.begin(), v.end());

	// VS는 음수일 때  나눗셈 기준이 다름
	// -5/2를 반올림하면 -3. 근데 VS에선 -2로 처리함
	if (sum > 0)
		cout << (int)((sum / (double)(N)) + 0.5) << "\n";
	else
		cout << (int)((sum / (double)(N)) - 0.5) << "\n";
	// 중앙값
	cout << v[N / 2] << "\n";
	// 최빈값
	vector<int> v2;
	for (int i = 0; i < MAX; i++) {
		if (used[i] == max_cnt)
			v2.push_back(i-4000);	// 0~8000
	}
	sort(v2.begin(), v2.end());
	if (v2.size() == 1)
		cout << v2[0] << "\n";
	// 두번째로 작은 값
	else
		cout << v2[1] << "\n";
	// 범위
	cout << v[v.size() - 1] - v[0] << "\n";
}