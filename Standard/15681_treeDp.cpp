// 201210 #15681 트리와 쿼리 Gold V
// 트리에서의 dp
// 그래프에서의 dp는 자신감으로 d 배열만 생성해주자
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
bool visit[MAX];
int d[MAX];	// 결과 메모이제이션
int N, R, Q;
int dfs(int x) {
	if (visit[x])
		return d[x];	// 메모이제이션 활용
	visit[x] = true;
	for (auto i : v[x]) {
		if (!visit[i]) {
			// 여기에 visit 처리해주면, 14번째 줄의
			// if문에서 바로 return해버림.
			d[x] = d[x] + dfs(i);
		}
	}
	return d[x];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> R >> Q;
	fill(d, d + MAX, 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// 메모이제이션을 미리 해놓으면
	dfs(R);
	// 쿼리마다 계산할 필요 없이 배열에서 값만 찾으면 됨.
	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << d[q] << "\n";
	}
}