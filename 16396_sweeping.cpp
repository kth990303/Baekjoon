// 200911 #16396 �� �׸��� Bronze I
// O(N^2)�� Ǯ�̵� �����ϳ�, ������ ���� �� O(N)����
// ������ �̿�
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10001;
const int INF = 1000000007;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	// ��, ��
	pair<int, int> p[MAX];
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = { a,b };
	}
	// ���� ��ǥ�� ���� ������ ����
	sort(p, p + N);
	int ans = 0;
	// ������ �ʱ�ȭ
	// �� ��, �ݵ�� s=e���� ��! 
	// ù��° ������ ���� ���� ��� ����
	int s = -INF, e = -INF;
	for (int i = 0; i < N; i++) {
		// ���ο� ���� ���� ����
		if (e < p[i].first) {
			ans += e - s;
			s = p[i].first;
			e = p[i].second;
		}
		else
			e = max(e, p[i].second);
	}
	// ������ ������ ���ؾߵ�
	ans += e - s;
	cout << ans << "\n";
}