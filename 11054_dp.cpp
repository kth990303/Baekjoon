// 200902 #11054 ���� �� ������� Gold III
// DP, LIS�� ����
// ó���� lower_bound�� �ߴٰ� �� ������ �ʿ������ ������
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int N;
int a[MAX];
int d[MAX], d2[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		d[i] = 1;	// ��� ���ڴ� ���� 1
		for (int j = 0; j <= i; j++) {
			// a[i]�� ���� �� ũ�ٸ�,
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				// dp�� ��������
				d[i] = d[j] + 1;
			}
		}
	}
	// ������� �����̹Ƿ� �����ε� ����
	for (int i = N - 1; i >= 0; i--) {
		d2[i] = 1;
		for (int j = N - 1; j >= i; j--) {
			if (a[j] < a[i] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1;
			}
		}
	}
	int ans = 0;
	// ��� ���ڴ� �ߺ��ǹǷ� 1�� ����ߵ�
	for (int i = 0; i < N; i++) {
		ans = max(ans, d[i] + d2[i] - 1);
	}
	cout << ans << "\n";
}