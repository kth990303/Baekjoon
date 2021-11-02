// 210118 #1914 �ϳ��� ž Silver II
// fuckin BigInteger (2^100-1)
#include <iostream>
#include <string>
using namespace std;
const int MOD = 1e9;
int N, K, num[101];
void solve(int h, int cur, int mid, int next) {
	if (h == 0)
		return;
	// cur: now, next: destination
	// 1->2
	solve(h - 1, cur, next, mid);
	cout << cur << " " << next << "\n";
	// 2->3
	solve(h - 1, mid, cur, next);
}
void bigNum(int n) {
	int cnt = 0;
	num[0] = 1;
	while (n--) {
		for (int i = 0; i <= cnt; i++) {
			num[i] *= 2;
		}
		for (int i = 0; i <= cnt; i++) {
			// if Integer is bigger than 1e9,
			// MOD���� Ŭ ���� MOD�� �����ְ�, ���� �ڸ��� num[i+1]��
			// ���� ���� �������ش�.
			if (num[i] >= MOD) {
				// num[i+1]: (10*i ~ 10*i + 9)th digit
				// ��, num[i+1]�� ���� 10*i~10*i+9��° �ڸ��� ����
				if (!num[i + 1])
					cnt++;
				num[i + 1] += num[i] / MOD;
				num[i] %= MOD;
			}
		}
	}
	for (int i = cnt; i >= 0; i--) {
		// ó������ �ݵ�� 9�ڸ��� �ƴϾ ������,
		// �߰��� 9�ڸ��� �ƴ� ���� ������ ä������Ѵ�.
		if (i!=cnt && to_string(num[i]).length() != 9) {
			for (int j = 0; j < 9 - to_string(num[i]).length(); j++) {
				cout << "0";
			}
		}
		// ���ڸ����� -1�� ����� �Ѵ�.
		if (!i)
			cout << num[i] - 1 << "\n";
		else
			cout << num[i];
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	bigNum(N);
	// ��� �̿��ϸ� ��
	if (N <= 20) {
		solve(N, 1, 2, 3);
	}
}