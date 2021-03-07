// 210307 #3830 교수님은 기다리지 않는다 Platinum III
// DS: Union_find
// segtree? LCA? We can solve easy to use disjoint_set
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, M, p[MAX], w[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	// All components update weight
	int tmp = find(p[a]);
	w[a] += w[p[a]];
	return p[a] = tmp;
}
bool merge(int a, int b, int weight) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb)
		return false;
	// Root parent update
	w[pb] = w[a]-w[b] + weight;
	p[pb] = pa;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			p[i] = i;
		}
		fill(w, w + MAX, 0);
		if (!N && !M)
			break;
		for (int i = 0; i < M; i++) {
			char ch;
			cin >> ch;
			if (ch == '!') {
				int a, b, weight;
				cin >> a >> b >> weight;
				merge(a, b, weight);
			}
			else {
				int a, b;
				cin >> a >> b;
				if (find(a) != find(b))
					cout << "UNKNOWN\n";
				else
					cout << w[b] - w[a] << "\n";
			}
		}
	}
}