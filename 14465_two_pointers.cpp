// 201229 #14465 �Ұ� ���� �ǳʰ� ���� 5 Silver II
// O(N^2)�� �ð��ʰ�. O(N)���� Ǯ��� ��.
// two_pointer �̿�. �˰��� �з��� �̺�Ž��, ������, ������
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int INF = 1e9 + 7;
int N, K, B, ans;
bool a[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K >> B;
	while (B--) {
		int n;
		cin >> n;
		a[n] = true;
	}
	int s = 1, e = K;
	for (int i = s; i <= e; i++) {
		if (a[i])
			ans++;
	}
	// ��ȣ�� ��ü �����۵���Ű�� �� ��
	if (K == N) {
		cout << ans << "\n";
		return 0;
	}
	// K<N �̾ e �������Ѽ� Ž���ؾ� �� ��
	int cnt = ans;
	e++;
	if (a[e])
		cnt++;
	while (1) {
		if (e - s + 1 == K) {
			ans = min(ans, cnt);
			if (e == N)
				break;
			e++;
			// ���� ��ȣ���� �����̸� ���� �߰�
			if (a[e])
				cnt++;
			continue;
		}
		else if (e - s + 1 > K) {
			if (a[s])
				cnt--;
			s++;
		}
		else {
			e++;
			if (a[e])
				cnt++;
		}
	}
	cout << ans << "\n";
}