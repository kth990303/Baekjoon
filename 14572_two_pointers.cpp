// 210429 #14572 스터디그룹 Platinum V
// two_pointers
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 100001;
int N, K, D;
vector<pair<int, vector<int>>> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K >> D;
	for (int i = 0; i < N; i++) {
		int M, d;
		cin >> M >> d;
		vector<int> algo(M);
		for (int j = 0; j < M; j++) {
			cin >> algo[j];
		}
		v.push_back({ d, algo });
	}
	sort(v.begin(), v.end());
	int s = 0, e = 0, ans = 0;
	map<int, int> m;
	for (auto i : v[0].second) {
		m[i]++;
	}
	while (s <= e) {
		int cnt = 0, people = e - s + 1;
		if (e >= N - 1 || v[e + 1].first - v[s].first > D) {
			for (auto i : v[s].second) {
				m[i]--;
				if (!m[i])
					m.erase(i);
			}
			s++;
			if (e < N - 1 && s>e) {
				e++;
				for (auto i : v[e].second) {
					m[i]++;
				}
				continue;
			}
			people--;
		}
		else {
			e++;
			people++;
			for (auto i : v[e].second) {
				m[i]++;
			}
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			if ((it->second) == people)
				cnt++;
		}
		ans = max(ans, people * ((int)m.size() - cnt));
	}
	cout << ans << "\n";
}