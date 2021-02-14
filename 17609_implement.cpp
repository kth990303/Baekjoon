// 210214 #17609 ȸ�� Silver I
// ����, �������� ����
// ��ͷ� �� ������ Ǯ �� �ִ� �� �ϴ�
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int check(string s) {
	// flag�̸� ȸ��, flag2�̸� ����ȸ��
	bool flag = true, flag2 = true;
	// del�� ���� Ƚ��
	int tmpi = 0, tmpj = 0, del = 0;
	for (int i = 0, j = 0;; i++, j++) {
		// �¿�Ʋ�ؼ� �߰��� �ڵ�
		if (i > s.length() - 1 - j)
			break;
		// ���� ��ġ���� �ʴ� ���ڰ� ��Ÿ���ٸ�
		if (s[i] != s[s.length() - 1 - j]) {
			// ȸ���� �ƴϴ�
			flag = false;
			// ������ 2�� �̻� �ߴٸ� ����ȸ���� �ƴϴ�
			if (del==2) {
				flag2 = false;
				break;
			}
			// ������ 1�� �ߴµ�, �ȸ´� ��찡 ���´ٰ�
			// �ٷ� flag2=false�� �ϸ� �ȵȴ�.
			// �� ������ �� else������ �� �� �ִ�
			else if (del==1) {
				i = tmpi;
				j = tmpj;
				del++;
				if (s[i + 1] == s[s.length() - 1 - j]) {
					i++;
					continue;
				}
			}
			else {
				// ������ �ؾ� �Ѵ�
				del++;
				// ���� ������ j��° ���ڸ� ������ ��
				// ���ڰ� ��ġ�Ѵٸ� �� ��츦 �����Ѵ�.

				// �ٵ� �� ��쿡�� ��ġ�Ѵ� �ϴ���,
				// �� ���� �����ϸ� 2�� �̻� �����ؾ� �ż� �Ұ����ϸ鼭
				// i��°���� �����ϴ� �� ����ȸ���� ������ ��찡 �ִ�
				// ���� �� ��찡 ������ ���, �� ���� else if���� ����ǵ��� �ؾ� �Ѵ�.
				// ���� ������ del==1�� �� ó�����ִ� �ڵ尡 �ִ� ��.
				if (s[i] == s[s.length() - 1 - (j + 1)]) {
					tmpi = i;
					tmpj = j;
					j++;
					continue;
				}
				else if (s[i + 1] == s[s.length() - 1 - j]) {
					tmpi = i;
					tmpj = j;
					i++;
					continue;
				}
				// �� �� �������� �ʴ´ٸ� �׳� ����ȸ���� �ƴ� ��
				flag2 = false;
				break;
			}
		}
	}
	if (flag)
		return 0;
	else if (flag2)
		return 1;
	return 2;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << check(s) << "\n";
	}
}