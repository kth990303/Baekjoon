// #3020 ���˹��� Gold V
// 1. prefix_sum 2. Binary Search
// crocus�� ��α׷� prefix_sum ��� ����
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500001;
const int INF = 1000000007;
int N, H, ans, cnt;
int a[MAX], b[MAX], totalA[MAX], totalB[MAX], total[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		int aVal, bVal;
		cin >> bVal >> aVal;
		a[aVal]++;
		b[bVal]++;
	}
	// ���� ������ �浹�ϴ� ��ֹ� ����
	// ������ i���� ���� �Ŵ� �� �浹�ϴϱ�
	totalA[H] = a[H];
	totalB[H] = b[H];
	for (int i = H - 1; i >= 1; i--) {
		totalA[i] = a[i] + totalA[i + 1];
		totalB[i] = b[i] + totalB[i + 1];
	}
	ans = INF;
	for (int i = 1; i <= H; i++) {
		total[i] = totalA[i] + totalB[H - i + 1];
		// �� ���� �浹�ϸ� ���� ����
		if (total[i] < ans) {
			cnt = 1;
			ans = total[i];
		}
		// ���� ������ ���� ��� cnt����
		else if (total[i] == ans) {
			cnt++;
		}
	}
	cout << ans << " " << cnt << "\n";
}