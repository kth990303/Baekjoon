// 200823 Sieve_Two Pointer Gold III
// 에라토스테네스와 투포인터 복습용으로 딱인 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 4000001;
int N;
int a[MAX];
bool isPrime[MAX];
void eratosthenes() {
	// N+1까지 안해주면 자기 자신은 false가 뜸
	fill(isPrime, isPrime + N+1, true);
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i])
			continue;
		// 배수인 것들은 소수 아니므로 false
		for (int j = i * 2; j <= N; j += i)
			isPrime[j] = false;
	}
	int j = 0;
	// a 배열에 N까지 소수들 넣어줌
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

	// 투포인터 시작~
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