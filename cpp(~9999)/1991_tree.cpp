// 200923 #1991 트리 순회 Silver I
// 트리의 순회. 트리의 기본 예제
// 트리의 성질: 벡터 이용하기 좋은 문제 -> 벡터 풀이법
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 27;
typedef pair<int, int> pii;
// leftChild, rightChild를 담기 위한 pair<int, int>
vector<pii> v[MAX];
int N;
// pre: (루트)(왼쪽 자식)(오른쪽 자식)
void pre(int cur) {
	// 루트
	cout << (char)(cur + 'A');
	for (auto i : v[cur]) {
		// 왼쪽 자식
		if(i.first!=-1)
			pre(i.first);
		// 오른쪽 자식
		if(i.second!=-1)
			pre(i.second);
	}
}
// in: (왼쪽 자식)(루트)(오른쪽 자식)
void in(int cur) {
	// 왼쪽 자식
	for (auto i : v[cur]) {
		if (i.first != -1)
			in(i.first);
	}
	// 루트
	cout << (char)(cur + 'A');
	// 오른쪽 자식
	for (auto i : v[cur]) {
		if (i.second != -1)
			in(i.second);
	}
}
// post: (왼쪽 자식)(오른쪽 자식)(루트)
void post(int cur) {
	for (auto i : v[cur]) {
		// 왼쪽 자식
		if (i.first != -1)
			post(i.first);
		// 오른쪽 자식
		if (i.second != -1)
			post(i.second);
	}
	// 루트
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
		// 트리 구현
		// vector에 담는 이유
		// v[root-'A']의 first, second에 담으면
		// v[first]에서는 또 v[first]만의 first, second가 있고
		// 결국 재귀적으로 가능
		// dfs가 가능한 이유를 생각하면 쉬움
		if (left != '.' && right != '.')
			v[root - 'A'].push_back({ left - 'A', right - 'A' });
		else if (left != '.' && right == '.')
			v[root - 'A'].push_back({ left - 'A', -1 });
		else if (left == '.' && right != '.')
			v[root - 'A'].push_back({ -1, right - 'A' });
	}
	// 전위 순회
	pre(0);
	cout << "\n";
	// 중위 순회
	in(0);
	cout << "\n";
	// 후위 순회
	post(0);
	cout << "\n";
}