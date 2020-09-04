// Trie 공부: kks227님 블로그 참고
// 200902 #5052 전화번호 목록 Gold IV
// Trie 기초개념문제
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int LEN_MAX = 10;	// 다음 문자로 올 수 있는 종류의 수
struct Trie {
	// 다음 문자 0~9 중 하나의 포인터
	Trie* next[LEN_MAX];
	// 이 노드가 끝인가?
	bool end;
	// 이 노드가 자식을 가지고 있는가?
	bool hasLeaf;
	// 트라이 생성자
	Trie() {
		fill(next, next + LEN_MAX, nullptr);
		end = false;
		hasLeaf = false;
	}
	// 트라이 소멸자
	~Trie() {
		for (int i = 0; i < LEN_MAX; i++) {
			if (next[i])
				delete next[i];
		}
	}
	// const char*로 안하면 문자열이 통째로 복사돼서 TLE
	void insert(const char* key) {
		// 문자열이 끝나는 경우
		if (*key == '\0') {
			end = true;
		}
		else {
			int x = *key - '0';
			// 해당 노드가 없을 경우 생성
			if (!next[x])
				next[x] = new Trie;
			// 자식 노드 있는게 맞음
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