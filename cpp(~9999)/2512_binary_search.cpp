// 201227 #2512 ���� Silver III
// Binary_search O(NlgM)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int N, M, a[MAX];
int solve(int s, int e) {
	// �̺� Ž�� �̿�: O(lgM)
	while (s <= e) {
		// s=e�� �� Ž���ϸ� c++ ������ ����
		// mid�� ���̿� ���� �ǵ�ġ ���� ���׵� ���� �� ����.
		int mid = (s + e) / 2;
		int sum = 0;
		// O(NlgM)�� ����
		for (int i = 0; i < N; i++) {
			sum += min(a[i], mid);
		}
		if (sum <= M)
			s = mid + 1;
		else
			e = mid - 1;
	}
	// ���� ��� s�� 1 �����������Ƿ� ���ϰ��� s-1
	return s - 1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int h = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		h = max(h, a[i]);
	}
	cin >> M;
	// M�� ���� s�� �ּҿ��Һ��� ���� �� �����Ƿ�
	// s�� 0���� e�� ���� �� �ִ� �ִ��.
	cout << solve(0, h) << "\n";
}