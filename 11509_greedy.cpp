// 210113 #11509 ǳ�� ���߱� Silver I
// Greedy
#include <iostream>
using namespace std;
const int MAX = 1000001;
int N, cnt[MAX], ans;
// ���� ǳ���� �������� ����
// ȭ���� ���ʿ��� ���������� ���Ƿ�, �־��� ������� ����ó���ϸ� ��
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (cnt[num + 1])
			cnt[num + 1]--;
		else
			ans++;
		cnt[num]++;
	}
	
	cout << ans << "\n";
}