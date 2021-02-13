// 210213 #2632 피자판매 Gold I
// N, M <= 1000 -> bruth-force 
// pizza size<=2,000,000 -> equal_range
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2001;
int K, N, M, ans;
int a[MAX], b[MAX], s1[MAX], s2[MAX];
vector<int> v1, v2;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		// because of circle pizza
		a[N + i] = a[i];
	}
	// prefix_sum
	for (int i = 1; i <= N * 2; i++) {
		s1[i] = s1[i - 1] + a[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> b[i];
		b[M + i] = b[i];
	}
	for (int i = 1; i <= M * 2; i++) {
		s2[i] = s2[i - 1] + b[i];
	}
	for (int j = 1; j <= N; j++) {
		for (int i = 0; i < N; i++) {
			// all sum
			if (j == N && i > 0)
				break;
			v1.push_back(s1[i + j] - s1[i]);
		}
	}
	for (int j = 1; j <= M; j++) {
		for (int i = 0; i < M; i++) {
			if (j == M && i > 0)
				break;
			v2.push_back(s2[i + j] - s2[i]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	// time complexity KlogK
	for (int i = 0; i <= K; i++) {
		auto it1 = equal_range(v1.begin(), v1.end(), i);
		auto it2 = equal_range(v2.begin(), v2.end(), K - i);
		if (!i)
			ans += (it2.second - it2.first);
		else if (i == K)
			ans += (it1.second - it1.first);
		else
			ans += (it1.second - it1.first) * (it2.second - it2.first);
	}
	
	cout << ans << "\n";
}