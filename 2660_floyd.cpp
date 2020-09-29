// 200930 #2660 회장뽑기 Gold V
// Floyd 풀이
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 51;
const int INF = 0x3f;
int N, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N;
	memset(d, INF, sizeof(d));
	// 자기 자신은 0점
	for (int i = 1; i <= N; i++)
		d[i][i] = 0;
	// 친구 관계 초기화 시작
	while (cin >> a >> b) {
		if (a == -1 && b == -1)
			break;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	vector<int> ans;
	int min_score = INF;
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		int num = 0;
		for (int j = 1; j <= N; j++) {
			num = max(num, d[i][j]);
		}
		min_score = min(min_score, num);
		res.push_back(num);
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == min_score)
			ans.push_back(i);
	}
	cout << min_score << " " << ans.size() << "\n";
	for (auto i : ans) {
		cout << i + 1 << " ";
	}
}