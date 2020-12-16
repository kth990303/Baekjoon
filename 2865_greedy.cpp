#include <iostream>
// 201216 #2865 ���� ������ ���۽�ŸK Silver IV
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
	// �帣�� ������ �����ϰ� ���̱� ���� ����ũ
	// ���� ����� ���� �帣�� �θ� �� �����Ƿ�
	// �׳� �ִ񰪸� ����־��ָ� �ȴ�.
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
	// �Ҽ��� ��°�ڸ����� �ݿø�
	// ǥ�� �˾Ƶα�
	cout << round(ans * 10) / 10.0 << "\n";
}