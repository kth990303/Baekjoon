#include <iostream>
using namespace std;
const int MAX = 100001;
int N, a[MAX], M, pSum[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		pSum[i] = pSum[i - 1] + a[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		// s�� ���� �տ� ���Եž� �ϹǷ�, pSum[s-1]�� ��
		cout << pSum[e] - pSum[s-1] << "\n";
	}
}