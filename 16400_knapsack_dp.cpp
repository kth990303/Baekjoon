// 200913 #16400 �Ҽ� ȭ�� Gold V
// O(N*�Ҽ�����+NlogN) -> O(N)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 40002;
const int MOD = 123456789;
vector<int> prime;
bool isPrime[MAX];
int N, d[MAX] = { 1, };
void eratosthenes() {
	fill(isPrime, isPrime + MAX, true);
	// �����佺�׳׽� ü�� �Ҽ� ����
	for (int i = 2; i * i < MAX; i++) {
		// �Ҽ��� �ƴ� ��� �������� �ʰ�
		if (!isPrime[i])
			continue;
		// �Ҽ��� ����� �͵��� false��
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
	// N���� �۰ų� ���� �Ҽ���θ� ����
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			prime.push_back(i);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	eratosthenes();
	// �� �ݾ׸��� �޸������̼����ִ� ���� dp
	for (int i = 0; i < prime.size(); i++) {
		for (int j = prime[i]; j <= N; j++) {
			d[j] += d[j - prime[i]];
			d[j] %= MOD;
		}
	}
	cout << d[N] << "\n";
}