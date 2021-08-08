// 210808 #17488 수강바구니 Silver V
// implementation
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 1001;
int N, M, a[MAX];
vector<int> v[MAX], d[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a[i];
	}
	for (int t = 1; t <= 2; t++) {
		for (int i = 1; i <= N; i++) {
			int n;
			while (cin >> n) {
				if (n == -1)
					break;
				d[n].push_back(i);
			}
		}
		for (int i = 1; i <= M; i++) {
			if (d[i].size() <= a[i]) {
				for (auto j : d[i]) {
					v[j].push_back(i);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		sort(all(v[i]));
		press(v[i]);
		if (!v[i].size())
			cout << "망했어요\n";
		else {
			for (auto j : v[i]) {
				cout << j << " ";
			}
			cout << "\n";
		}	
	}
}