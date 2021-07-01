// 210701 #2493 ž Gold V
// use stack
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
int N, n;
vector<pi> ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> n;
	cout << 0 << " ";
	ans.push_back({ n, 1 });
	for (int i = 2; i <= N; i++) {
		int n;
		cin >> n;
		while (!ans.empty() && ans.back().first < n) {
			ans.pop_back();
		}
		cout << (ans.empty() ? 0 : ans.back().second) << " ";
		ans.push_back({ n, i });
	}
}