// 201212 #2447 �����-10 Silver I
// ��Ϳ� ���� ���� �ܿ� �ڵ� ������, ��� ������ �ʿ���.
// ��Ͱ� ���� 9����.
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N;
const int MAX = 6561;
char map[MAX][MAX];	// "\n"ó�������� ���� �迭�� ����
void solve(int x, int a, int b) {
	if (x == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					map[a + i][b + j] = ' ';
				else
					map[a + i][b + j] = '*';
			}
		}
		return;
	}
	// ��Ͱ� 9�������� �������� �ִµ� ���⼺�� �ִ�
	// �׷� �ٷ� for���� ����߰ڴ�
	// ��, ����� ��͸� ���� �ʴ´�.
	// ����� ��� ó���ұ�? ����� ���� ' '�� �ִ� ����� ������
	// ���ʿ� �ʱ�ȭ�� ' '�� ��Ű�� ����.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			solve(x / 3, a + x * i / 3, b + x * j / 3);
		}
	}
	
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	memset(map, ' ', sizeof(map));
	solve(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}