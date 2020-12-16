#include <iostream>
// 201216 #2865 나는 위대한 슈퍼스타K Silver IV
// greedy
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M, K;
double ans;
vector<double> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(1);

	cin >> N >> M >> K;
	v.resize(N + 1, 0);
	// 장르는 문제를 복잡하게 보이기 위한 훼이크
	// 여러 사람이 같은 장르를 부를 수 있으므로
	// 그냥 최댓값만 집어넣어주면 된다.
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int k;
			double score;
			cin >> k >> score;
			v[k] = max(v[k], score);
		}
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < K; i++) {
		ans += v[i];
	}
	// 소수점 둘째자리에서 반올림
	// 표현 알아두기
	cout << round(ans * 10) / 10.0 << "\n";
}