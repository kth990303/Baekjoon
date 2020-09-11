// 200911 #11053 LIS 1 Silver II
// ���Ҿ� ��� O(N^2)
// �� �� �����س���
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, a[MAX], cache[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(cache, cache + MAX, 1);
	int ans = 1;	// �׻� ���̴� 1. �̰� ���ϸ� 99%���� Ʋ��
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			// ���� ������ ũ�鼭, ���̰� �� ������� ���
			if (a[i] > a[j] && cache[i] < cache[j] + 1) {
				cache[i] = cache[j] + 1;
			}
		}
		// ���� �� ���̷�
		ans = max(ans, cache[i]);
	}
	cout << ans << "\n";
}