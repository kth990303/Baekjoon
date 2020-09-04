// Trie ����: kks227�� ��α� ����
// 200902 #5052 ��ȭ��ȣ ��� Gold IV
// Trie ���ʰ��乮��
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int LEN_MAX = 10;	// ���� ���ڷ� �� �� �ִ� ������ ��
struct Trie {
	// ���� ���� 0~9 �� �ϳ��� ������
	Trie* next[LEN_MAX];
	// �� ��尡 ���ΰ�?
	bool end;
	// �� ��尡 �ڽ��� ������ �ִ°�?
	bool hasLeaf;
	// Ʈ���� ������
	Trie() {
		fill(next, next + LEN_MAX, nullptr);
		end = false;
		hasLeaf = false;
	}
	// Ʈ���� �Ҹ���
	~Trie() {
		for (int i = 0; i < LEN_MAX; i++) {
			if (next[i])
				delete next[i];
		}
	}
	// const char*�� ���ϸ� ���ڿ��� ��°�� ����ż� TLE
	void insert(const char* key) {
		// ���ڿ��� ������ ���
		if (*key == '\0') {
			end = true;
		}
		else {
			int x = *key - '0';
			// �ش� ��尡 ���� ��� ����
			if (!next[x])
				next[x] = new Trie;
			// �ڽ� ��� �ִ°� ����
			hasLeaf = true;
			next[x]->insert(key + 1);
		}
	}
	bool flag() {
		if (end && hasLeaf)
			return false;
		for (int i = 0; i < LEN_MAX; i++) {
			if (next[i] && !next[i]->flag())
				return false;
		}
		return true;
	}
};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		Trie* root = new Trie;
		for (int i = 0; i < N; i++) {
			char num[11];
			cin >> num;
			root->insert(num);
		}
		if (root->flag())
			cout << "YES\n";
		else
			cout << "NO\n";
		delete root;
	}
}