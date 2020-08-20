// 200820 #11505 Segment Tree_Platinum V
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[1000001];
ll tree[4000004];
const ll INF = 1000000007;
int N, M, K;
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = ((init(node * 2, s, mid)%INF) 
		* (init(node * 2 + 1, mid + 1, e)%INF))%INF;
}
ll multiple(int node, int s, int e, int left, int right) {
	// mul, div는 기본 1
	if (right<s || left>e)
		return 1;
	if (s <= left && right <= e) {
		return tree[node];
	}
	int mid = (left + right) / 2;
	return ((multiple(node * 2, s, e, left, mid)%INF) 
		* (multiple(node * 2 + 1, s, e, mid + 1, right)%INF))%INF;
}
ll update(int node, int left, int right, int idx, int post) {
	if (idx<left || idx>right)
		return tree[node];
	// left와 right가 같을 때만 변경
	if(left==right)
		return tree[node] = post;
	// 같지 않을 경우는 update로 값을 반환시켜 변경
	int mid = (left + right) / 2;
	return tree[node]=(update(node * 2, left, mid, idx, post) % INF)
		*(update(node * 2 + 1, mid + 1, right, idx, post) % INF) % INF;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	for (int i = 1; i <= M + K; i++) {
		int ch;
		cin >> ch;
		if (ch == 1) {
			int b, c;
			cin >> b >> c;
			update(1, 1, N, b, c);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << multiple(1, b, c, 1, N) << "\n";
		}
	}
}