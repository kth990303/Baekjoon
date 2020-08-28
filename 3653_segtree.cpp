// 200828 #3653 영화수집 Platinum IV
// queue 데이터 탐색: 100*O(NM)=100*O(N^2)
// segment tree 이용-> 구간 합
// 처음엔 lazy propagation 떠올렸음
// 그 다음엔 update idx를 두 개를 주고(바뀌는 거 2개)
// 진행했으나, 로직 잘못짜서 첨부터 다시^^...
// 그러다가 또 복잡해져서 다시...
// 연습이 많이 필요할듯
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
const int MAX = 200001;	// N+M. 이게 젤 떠올리기 힘들었음
using namespace std;
int a[MAX];	// DVD node index 저장
int N, M;
int init(vector<int>& tree, int node, int s, int e) {
	if (s == e) {
		if (s > M) {
			a[s-M] = s;
			tree[node] = 1;
		}
		return tree[node];
	}
	int mid = (s + e) / 2;
	return tree[node] = init(tree, node * 2, s, mid)
		+ init(tree, node * 2 + 1, mid + 1, e);
}
int query(vector<int>& tree, int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right) {
		return tree[node];
	}
	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, left, right)
		+ query(tree, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<int>& tree, int node, int s, int e, int idx, int num) {
	if (idx > e || idx < s)
		return;
	if (s==e) {
		tree[node] = num;
		return;
	}
	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, idx, num);
	update(tree, node * 2 + 1, mid + 1, e, idx, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int size = ceil(log2(MAX));
	int tree_size = 4 + (1 << (size + 1));
	
	/*
	2
	3 3
	3 1 1
	5 3
	4 4 5
	ans
	2 1 0
	3 0 4
	*/
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> M;
		vector<int> tree(tree_size, 0);
		fill(a, a + MAX, 0);

		init(tree, 1, 1, M+N);
		for (int i = 1; i <= M; i++) {
			int movie;
			cin >> movie;
			// update 어려움. 조금 더 생각해보자
			cout << query(tree, 1, 1, M + N, 1, a[movie] - 1) << " ";
			// a[movie]가 0이 된 거, M-i+1가 movie가 된 거를 업데이트
			// 업데이트는 한꺼번에 하지말고 나눠서 하자.....
			update(tree, 1, 1, M + N, a[movie], 0);
			a[movie] = M - i + 1;
			update(tree, 1, 1, M+N, a[movie], 1);
		}
		cout << "\n";
	}
}