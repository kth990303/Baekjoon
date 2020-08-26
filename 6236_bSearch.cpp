#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2000000000;
int N, M, a[100000];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int s = 0, e = INF;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	while (s<=e) {
		int cnt = 1;
		int mid = (s + e) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			// �Ϸ� ����׺��� ���ⷮ�� ������ �ȵ�
			if (a[i] > mid) {
				cnt = INF;
				break;
			}
			if (sum + a[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += a[i];
		}
		// 1�� �� ����ó���� �� ����� �Ѵ�
		if (M == 1) {
			cout << sum;
			return 0;
		}
		// �ּҰ��� ���ϴ� ����
		// ���� ��� �� �ּ��� ���� ���ؾ� �ϹǷ�
		// ���� ���� e�� ������
		if (cnt <= M)
			e = mid - 1;
		else
			s = mid + 1;
	}
	// �������� s=e�� ���� e=mid-1�� �����Ƿ�
	// e+1�� �������� ����
	cout << e + 1;
}