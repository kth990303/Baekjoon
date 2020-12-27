// 201227 #16456 �ϿͿ� ���л�» �Ͽ��̷� ���� �ŽÿͿ�~ Silver I
// DP(BU) �ð����⵵: O(N)
// �Ϲ��� ���� Ȥ�� ��������� ����
#include <iostream>
using namespace std;
const int MAX = 50001;
typedef long long ll;
ll N, d[MAX] = { 0,1,1,2 };
const ll MOD = 1e9 + 9;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 4; i <= N; i++) {
		// ��ĭ ���� �� �ǵ��ư��ٰ� ���� ��� + �� ĭ ���� ���
		d[i] = (d[i - 1] + d[i - 3]) % MOD;
	}
	cout << d[N] << "\n";
}