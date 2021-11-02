// 201207 #9376 상근이의 여행 Silver III
// MST이나, 가중치가 없어 dfs로도 접근 가능... 하나,
// 사실 상 N-1이 답이어서 print(n-1)도 정답.
#include <iostream>
#include <vector>
using namespace std;
int N, M, ans;
const int MAX = 10001;
vector<int> v[MAX];
int p[1001];	// mst를 하기 위한 컴포넌트 대표번호 배열
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

	int t;
	cin >> t;
	while (t--) {
		for (auto& i : v)
			i.clear();
		ans = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			p[i] = i;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (merge(i, j))
					ans++;
			}
		}
		cout << ans << "\n";
	}
}