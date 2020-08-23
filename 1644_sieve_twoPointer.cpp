// 200823 Sieve_Two Pointer Gold III
// �����佺�׳׽��� �������� ���������� ���� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 4000001;
int N;
int a[MAX];
bool isPrime[MAX];
void eratosthenes() {
	// N+1���� �����ָ� �ڱ� �ڽ��� false�� ��
	fill(isPrime, isPrime + N+1, true);
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i])
			continue;
		// ����� �͵��� �Ҽ� �ƴϹǷ� false
		for (int j = i * 2; j <= N; j += i)
			isPrime[j] = false;
	}
	int j = 0;
	// a �迭�� N���� �Ҽ��� �־���
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			a[j++] = i;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	eratosthenes();

	// �������� ����~
	int sum = 0, ans = 0, s = 0, e = 0;
	while (1) {
		if (sum >= N)
			sum -= a[s++];
		else if (e != N)
			sum += a[e++];
		else
			break;
		if (sum == N)
			ans++;
	}
	cout << ans;
}