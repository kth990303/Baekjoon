// 200830 #2467 ��� Gold V
// ��Ʈ��ŷ�� ���÷ȴٸ�... TLE
// �̰� ���������� ���� ������ �Ѵ�
// �ٸ�, s=0, e=1 �̷��� �ϸ� ���� ����� ���ϱ� ��������
#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 2000000007;	//10��*2 �̻����� �ؾߵ�!
using namespace std;
int N;
vector<int> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int s = 0, e = N - 1, sum = INF;
	int ans1 = 0, ans2 = 0;
	while (1) {
		if (s == e)
			break;
		if (abs(v[s] + v[e]) < sum) {
			ans1 = v[s];
			ans2 = v[e];
			sum = abs(v[s] + v[e]);
		}
		if (v[s] + v[e] > 0) {
			e--;
		}
		else {
			s++;
		}
	}
	cout << ans1 << " " << ans2 << "\n";
}