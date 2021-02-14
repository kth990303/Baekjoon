// 210214 #4375 1 Silver III
// Bruth-Force
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 10001;
ll N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	// �� string���� �ϸ� ��Ÿ�� ������ �ߴ��� �𸣰ڴ�
	while (cin >> N) {
		// n�� N���� ���� ������.
		ll n = 1 % N;
		for (int i = 1;; i++) {
			// �������� 0�̸� ����� ��
			if (!n) {
				cout << i << "\n";
				break;
			}
			// 1�� �̾ �ٿ��� %N�� �����ش�.
			n *= 10;
			n++;
			n %= N;
		}
	}
}