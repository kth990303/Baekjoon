// 201229 #14942 ���� Platinum V
// sparse_table O(nlgn) (lca�� �ƴ����� �����ϱ⿡ ����)
// dfs+sparse_table �Ǵ� bfs+sparse_table
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100001;
const int SIZE = 17;
vector<pair<int, int>> v[MAX];
int N, hp[MAX], p[MAX][SIZE], d[MAX], cost[MAX][SIZE];
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.second] == -1) {
			// cost (ü�� �Ҹ�) �迭 ���� ������ش�.
			cost[i.second][0] = i.first;
			// ����� ���� ����
			d[i.second] = d[cur] + 1;
			// �θ� ����
			p[i.second][0] = cur;
			init(i.second);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> hp[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[1] = 0;
	init(1);	// ���� lca�� ����
	// �� SIZE-1����?
	// j+1=SIZE-1�̱� ������. �迭 index ��������.
	for (int j = 0; j < SIZE - 1; j++) {
		for (int i = 2; i <= N; i++) {
			if (p[i][j] != -1) {
				p[i][j + 1] = p[p[i][j]][j];
				cost[i][j + 1] = cost[i][j] + cost[p[i][j]][j];
			}
			// else���� ������ ������ ��Ʈ���� �� �� �ְ� ��.
			else
				cost[i][j + 1] = cost[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		// �� ������ lca�� �ƴ� ����
		// �� ���� ��尡 �ִ� �󸶱��� �ö� �� �ִ���
		// ���������� ���ϴ� ������ �ƴ�
		int a, k;
		a = i, k = hp[i];
		if (i == 1) {
			cout << "1\n";
			continue;
		}
		for (int j = SIZE - 1; j >= 0; j--) {
			if (a == -1)
				break;
			if (k >= cost[a][j]) {
				k -= cost[a][j];
				a = p[a][j];	// -1�� ��� ��Ʈ��� �̻�
			}
		}
		if (a == -1)
			a = 1;
		// �� �ڵ� ��� �Ǵµ�, �� �� �κ��� ������ 20ms�� �� ������..?
		else if (k >= cost[a][0])
			a = p[a][0];
		cout << a << "\n";
	}
}