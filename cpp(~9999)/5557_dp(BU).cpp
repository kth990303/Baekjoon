// 201228 #5557 1�г� Gold V
// ��Ʈ��ŷ? dp? d[i][j]�� �޸������̼��ص� �ǹǷ� dp~ (���� ���� ��������)
// O(N*20) (���Ҿ� ��ȭ�� ���: ������ �� ��������)
#include <iostream>
const int MAX = 101;
using namespace std;
typedef long long ll;
ll N, a[MAX], d[MAX][21];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	d[0][a[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (d[i - 1][j]) {
				if (j + a[i] <= 20)
					d[i][j + a[i]] += d[i - 1][j];
				if (j - a[i] >= 0)
					d[i][j - a[i]] += d[i - 1][j];
			}
		}
	}
	cout << d[N - 2][a[N - 1]] << "\n";
}