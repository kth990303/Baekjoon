// 200911 #15966 �������� Silver II
// LIS ����������, 1 �������� �ŹǷ� �� �� ������ ����
// ������, �� ���⼭�� ��̴�...
// ���Ҿ� ���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int VAL_MAX = 1000002;
int N, a[MAX], cache[VAL_MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(cache, cache + MAX, -1);
	int ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (cache[a[i] - 1] == -1) {
			cache[a[i]] = 1;
		}
		else {
			cache[a[i]] = cache[a[i] - 1] + 1;
			ans = max(ans, cache[a[i]]);
		}
	}
	cout << ans << "\n";
}