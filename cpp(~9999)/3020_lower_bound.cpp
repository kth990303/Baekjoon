// #3020 °³¶Ë¹ú·¹ Gold V
// 1. prefix_sum 2. Binary Search
// 2. BSearch_lower_bound
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 200001;
const int INF = 1000000007;
int N, H, total[MAX];
vector<int> a, b;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		int aVal, bVal;
		cin >> bVal >> aVal;
		a.push_back(aVal);
		b.push_back(bVal);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < H; i++) {
		int aNum = a.size() - (lower_bound(a.begin(), a.end(), i) - a.begin());
		int bNum = b.size() - (lower_bound(b.begin(), b.end(), H - i + 1) - b.begin());
		total[aNum + bNum]++;
	}
	for (int i = 0; i <= N; i++) {
		if (total[i]) {
			cout << i << " " << total[i] << "\n";
			return 0;
		}
	}
}