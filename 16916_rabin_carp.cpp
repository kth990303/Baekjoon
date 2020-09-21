// ���-ī�� �˰���
// �ּ�: O(N+M), �־�: O(NM)
// ���� �ؽ��Լ��� ����� ���� �ٽ� (��: ��� �ΰ�����Ʈ)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MOD = 127;
const int base = 256;
string s, p;
// �ؽ��Լ�: Rabin-FingerPrint
// abcd: (97*256^3 + 98*256^2 + 99*256 + 100) % MOD
// ���� ��ġ�� �ؽð��� �ٷ� ���� �� �ֱ� ������ ���� �̿�
int h(string s) {
	int ans = 0;
	for (char ch : s) {
		ans = (ans * base + ch) % MOD;
	}
	return ans;
}
int match(string s, string p) {
	int n = s.length();
	int m = p.length();
	if (n < m)
		return 0;
	int hash_p = h(p);
	int hash_s = h(s.substr(0, m));
	// first= pow(base, m-1)%MOD
	// ���� ���ڿ� �� ��, hash_s���� ��������� �ϹǷ�
	int first = 1;
	for (int i = 0; i < m - 1; i++) {
		first = (first * base) % MOD;
	}
	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) {
			if (s.substr(i, m) == p)
				return 1;
		}
		if (i + m < n) {
			hash_s = hash_s - (s[i] * first) % MOD;
			// hash_s�� ������ �� �� �����Ƿ�
			hash_s = (hash_s + MOD) % MOD;
			hash_s = ((hash_s * base) % MOD + s[i + m]) % MOD;
		}
	}
	return 0;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> p;
	cout << match(s, p) << "\n";
}