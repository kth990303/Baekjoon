// 200829 #3176 도로 네트워크 Platinum IV
// 도로 길이의 합 구하는게 아니라 가장 짧은 거 긴거
// 합이면 MST 쓸까 했더니만,,, ㅠㅠ -> LCA로 가자~
// 짧은거, 긴거까지 시간 고려해서 배열 추가로 만들자
// 그외엔 LCA랑 비슷한 듯~
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
const int INF = 1000000007;
const int MAX = 100001;
const int SIZE = 17;	// 2^16=65536
using namespace std;
int p[MAX][SIZE + 1];
int d[MAX];
int l[MAX][SIZE + 1];	// 가장 긴 거
int s[MAX][SIZE + 1];	// 가장 짧은 거
vector<pair<int, int>> v[MAX];
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.second] == -1) {
			d[i.second] = d[cur] + 1;
			p[i.second][0] = cur;

			l[i.second][0] = i.first;
			s[i.second][0] = i.first;
			init(i.second);
		}
	}
}
int N, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j <= SIZE; j++) {
			s[i][j] = INF;
			l[i][j] = -1;
		}
	}
	d[1] = 0;
	init(1);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 2; i <= N; i++) {
			int tmp = p[i][j];
			if (tmp != -1) {
				p[i][j + 1] = p[tmp][j];
				s[i][j + 1] = min(s[i][j], s[tmp][j]);
				l[i][j + 1] = max(l[i][j], l[tmp][j]);
			}
		}
	}
	cin >> K;
	while (K--) {
		int ans1, ans2;	// short, long
		ans1 = INF;
		ans2 = -1;
		int a, b;
		cin >> a >> b;
		if (d[a] < d[b])
			swap(a, b);
		int diff = d[a] - d[b];

		int j = 0;
		while (diff) {
			if (diff % 2) {
				ans1 = min(ans1, s[a][j]);
				ans2 = max(ans2, l[a][j]);
				// 순서 어기면 바뀜
				// 안바꾸면 예제 세번째 쿼리 이상할거임
				// 순서 바꾸면 자신 꺼는 포함이 전혀 안됨
				a = p[a][j];
			}
			diff /= 2;
			j++;
		}
		if (a != b) {
			for (int i = SIZE; i >= 0; i--) {
				if (p[a][i] != -1 && p[a][i] != p[b][i]) {
					ans1 = min(ans1, min(s[a][i], s[b][i]));
					ans2 = max(ans2, max(l[a][i], l[b][i]));
					// 이것도 순서... ans먼저!
					a = p[a][i];
					b = p[b][i];
				}
			}
			ans1 = min(ans1, min(s[a][0], s[b][0]));
			ans2 = max(ans2, max(l[a][0], l[b][0]));
		}
		cout << ans1 << " " << ans2 << "\n";
	}
}