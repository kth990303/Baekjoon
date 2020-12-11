// 201212 #11729 �ϳ��� ž �̵����� Silver II
// ��� ������ Ǯ ���� ����
// ���(Standard)�� Ǯ ���� ū Ʋ�� ¥�� �������� ��ǻ�Ϳ� �ñ��
// ��� ȣ��Ǵ� ������ �ϳ��� ������ ����
#include <iostream>
using namespace std;
int N;
// d[5]=d[4]+5��° ����+������ 4���� ����
// d[4]�� ��Ͱ� �˾Ƽ� ���ְ��� ��� ���ε��.
void solve(int h, int cur, int tmp, int next) {
	if (!h)
		return;
	// ���ݺ�
	solve(h - 1, cur, next, tmp);
	// ��� (�� �Ʒ� ����)
	cout << cur << " " << next << "\n";
	// �Ĺݺ�
	solve(h - 1, tmp, cur, next);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	// bitmask
	cout << (1 << N) - 1 << "\n";
	solve(N, 1, 2, 3);
}