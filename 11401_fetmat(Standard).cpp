// 200909 #11401 ���װ��3 Gold I
// �丣���� ������, �������� �̿�
// �޸𸮸� �ξ� �Ƴ��� Ǯ��
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 4000001;
const ll MOD = 1000000007;
ll N, K;	// ���� ���丮���� �޸������̼����� ����
ll fpow(ll val, ll idx) {
	ll ret = 1;
	while (idx > 0) {
		if (idx % 2) {
			ret *= val;
			ret %= MOD;
		}
		val *= val;
		val %= MOD;
		idx /= 2;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	ll A = 1, B = 1;
	// N! ���
	for (int i = 1; i <= N; i++) {
		A *= (ll)i;
		A %= MOD;
	}
	// K!(N-K)! ���
	for (int i = 1; i <= K; i++) {
		B *= (ll)i;
		B %= MOD;
	}
	for (int i = 1; i <= N - K; i++) {
		B *= (ll)i;
		B %= MOD;
	}
	// B�� �丣�� �������� ���� (n-k)!k!�� p-2����
	// B^(p-2)%p = 1/B %p �̹Ƿ�
	B = fpow(B, MOD - 2);
	ll ans = (A * B) % MOD;
	cout << ans << "\n";
}