// 200817 #1275 Platinum V segtree
// 2042���̶� ������
// #1275 �߰�����
//8 4
//1 3 5 7 9 11 13 15
//2 3 3 1
//8 5 4 2
//1 8 3 100000
//2 6 1 4
//
//output
//8
//48
//55
//100025
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A[100001];
ll tree[400004];
int N, Q;
// tree �ʱ�ȭ
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node] = A[s];
	int mid = (s + e) / 2;
	return tree[node]=init(node*2, s, mid) + init(node*2+1, mid + 1, e);
}
// ���ϴ� ����: [s, e]
// ��� ����: [left, right]
ll sum(int node, int s, int e, int left, int right) {
	if (right<s || left>e)
		return 0;
	if (s <= left && right <= e)
		return tree[node];
	int mid = (left + right) / 2;
	return sum(node * 2, s, e, left, mid) + sum(node * 2 + 1, s, e, mid + 1, right);
}
// �ؿ� ��嵵 update ���ֱ�
// diff�� �ڷ��� ����!
void update(int node, int left, int right, int idx, ll diff) {
	if (idx<left || idx>right)
		return;
	tree[node] += diff;

	if (left != right) {
		int mid = (left + right) / 2;
		update(node * 2, left, mid, idx, diff);
		update(node * 2 + 1, mid + 1, right, idx, diff);
	}

}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	init(1, 1, N);
	while (Q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)
			cout << sum(1, y, x, 1, N) << "\n";
		else
			cout << sum(1, x, y, 1, N) << "\n";
		// �ڷ��� ����!
		ll diff = b - A[a];
		// �̰� ��ġ�� ū�ϳ���...!
		A[a] = b;
		update(1, 1, N, a, diff);
	}
}