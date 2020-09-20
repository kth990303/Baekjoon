// 200921 #10972 ���� ���� Silver III
// ����� next_permutation
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 10001;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	do {
		// ���� ������ ������Ű�� ����
		if (!cnt) {
			cnt++;
			continue;
		}
		// (1) cnt=0�� �� �������̾�����
		// �̺κ��� �۵����� ���ϰ� ����
		if (cnt == 1) {
			for (auto i : v)
				cout << i << " ";
			cnt++;
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
	// (1)�� ���, -1 ����ϰ� ��
	if (cnt == 1)
		cout << -1 << "\n";
}