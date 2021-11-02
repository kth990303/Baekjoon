// 200923 #1991 Ʈ�� ��ȸ Silver I
// Ʈ���� ��ȸ. Ʈ���� �⺻ ����
// Ʈ���� ����: ���� �̿��ϱ� ���� ���� -> ���� Ǯ�̹�
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 27;
typedef pair<int, int> pii;
// leftChild, rightChild�� ��� ���� pair<int, int>
vector<pii> v[MAX];
int N;
// pre: (��Ʈ)(���� �ڽ�)(������ �ڽ�)
void pre(int cur) {
	// ��Ʈ
	cout << (char)(cur + 'A');
	for (auto i : v[cur]) {
		// ���� �ڽ�
		if(i.first!=-1)
			pre(i.first);
		// ������ �ڽ�
		if(i.second!=-1)
			pre(i.second);
	}
}
// in: (���� �ڽ�)(��Ʈ)(������ �ڽ�)
void in(int cur) {
	// ���� �ڽ�
	for (auto i : v[cur]) {
		if (i.first != -1)
			in(i.first);
	}
	// ��Ʈ
	cout << (char)(cur + 'A');
	// ������ �ڽ�
	for (auto i : v[cur]) {
		if (i.second != -1)
			in(i.second);
	}
}
// post: (���� �ڽ�)(������ �ڽ�)(��Ʈ)
void post(int cur) {
	for (auto i : v[cur]) {
		// ���� �ڽ�
		if (i.first != -1)
			post(i.first);
		// ������ �ڽ�
		if (i.second != -1)
			post(i.second);
	}
	// ��Ʈ
	cout << (char)(cur + 'A');
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		// Ʈ�� ����
		// vector�� ��� ����
		// v[root-'A']�� first, second�� ������
		// v[first]������ �� v[first]���� first, second�� �ְ�
		// �ᱹ ��������� ����
		// dfs�� ������ ������ �����ϸ� ����
		if (left != '.' && right != '.')
			v[root - 'A'].push_back({ left - 'A', right - 'A' });
		else if (left != '.' && right == '.')
			v[root - 'A'].push_back({ left - 'A', -1 });
		else if (left == '.' && right != '.')
			v[root - 'A'].push_back({ -1, right - 'A' });
	}
	// ���� ��ȸ
	pre(0);
	cout << "\n";
	// ���� ��ȸ
	in(0);
	cout << "\n";
	// ���� ��ȸ
	post(0);
	cout << "\n";
}