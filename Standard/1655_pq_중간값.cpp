// 200912 #1655 ����� ���ؿ� Gold II
// �ּ����� �ִ����� �̿�
// ������ £�� �� �����Ƿ� �˾Ƶ���
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//�ִ� ������ a[N/2]������ ���� ������
	//�ּ� ������ �ִ������� ū ������
	//�ִ� ���� ���� ū ���� (top)�� �߰���
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		// pq1�� �־��ֱ�
		if (pq1.size() == pq2.size()) {
			pq1.push(k);
		}
		// pq1 ����� �� ū ��� pq2�� �־��ֱ�
		else {
			pq2.push(k);
		}
		// pq2�� �ּҰ� pq1�� �ִ뺸�� Ŀ�� ��
		// ���� ���� ���� swap�����൵��
		if (!pq2.empty() && pq1.top() > pq2.top()) {
			int top1 = pq1.top();
			int top2 = pq2.top();
			pq1.pop();
			pq2.pop();
			pq1.push(top2);
			pq2.push(top1);
		}
		cout << pq1.top() << "\n";
	}
}