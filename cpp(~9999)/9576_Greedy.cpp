// 200829 #9576 å �����ֱ� Gold I
// ���� ������ Greedy, �̺и�Ī�� ����
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, ans;
// ���� ����
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> N >> M;
		ans = 0;
		vector<pair<int, int>> v;
		bool use[1001];	// å ��������� ����
		fill(use, use + 1001, false);

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			for (int j = v[i].first; j <= v[i].second; j++) {
				if (!use[j]) {
					use[j] = true;
					ans++;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}