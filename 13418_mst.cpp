// 200909 #13418 �б� Ž���ϱ� Gold III
// MST�� �� ���ؼ� �ذ�.
// �� ���ؼ� �ذ�Ǵ� Ǯ�̵� ������ ���߿� �η����� �� �����ϱ�
// �� �̴�� Ŀ���ҷ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, M, cnt1, cnt2;	// �������� ����
int p[MAX];
vector<pair<int, pair<int, int>>> bestV, worstV;
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M + 1; i++) {
		int a, b, ch;
		cin >> a >> b >> ch;
		// best�� �־��̴�... �ݴ�� �ƴ�...
		// ���������� 1���� �˾Ҵ�...
		bestV.push_back({ ch, {a,b} });
		// worst�� �ּ���... ��ư !ch �ϸ� �ݴ�� sort �Ǵϱ�
		worstV.push_back({ !ch, {a,b} });
	}
	sort(bestV.begin(), bestV.end());
	sort(worstV.begin(), worstV.end());
	// �־��� ���(...) ���ϱ�
	for (int i = 0; i < bestV.size(); i++) {
		int node1 = bestV[i].second.first;
		int node2 = bestV[i].second.second;
		int cost = bestV[i].first;
		if (merge(node1, node2)) {
			if (!cost)
				cnt1++;
		}
	}
	// �ּ��� ��� ���ϱ�
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}
	for (int i = 0; i < worstV.size(); i++) {
		int node1 = worstV[i].second.first;
		int node2 = worstV[i].second.second;
		int cost = worstV[i].first;
		if (merge(node1, node2)) {
			if (cost) {
				cnt2++;
			}
		}
	}
	// ����: ������ ������
	cout << cnt1 * cnt1 - cnt2 * cnt2 << "\n";
}