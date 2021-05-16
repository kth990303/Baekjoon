// 210516 #16566 카드 게임 Platinum V
// I think it's Gold II ~ Gold I 
// because of #10775
// union_find
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 4000001;
int N, M, K, p[MAX];
vector<int> v;
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

	cin >> N >> M >> K;
	v.resize(M);
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;
		int idx = lower_bound(v.begin(), v.end(), k) - v.begin();
		for (int j = idx; j < v.size(); j++) {
			if (k < v[j] && find(k) != find(v[j])) {
				cout << v[j] << " ";
				merge(k, v[j]);
				break;
			}
		}
	}
}