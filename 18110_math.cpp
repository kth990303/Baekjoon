// #18110 solved.ac Silver IV
// 임의정밀도 및 반올림 (round 이용 안한 풀이임)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<double> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	double N, p, ans = 0;
	cin >> N;
	if (!N) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		double k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	p = (int)(N * 0.15 + 0.5);
	for (int i = p; i < N - p; i++) {
		ans += v[i];
	}
	ans /= (double)(N - (double)2*p);
	cout << (int)(ans + 0.5) << "\n";
}