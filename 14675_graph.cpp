// 210922 #14675 단절점과 단절선 Gold V
// articulation in tree -> easy
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
int N, Q, in[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		in[a]++; in[b]++;
	}
	cin >> Q;
	while (Q--) {
		int t, k;
		cin >> t >> k;
		if (t == 2)
			cout << "yes\n";
		else if (t == 1 && in[k] != 1)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}