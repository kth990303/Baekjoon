// 210812 #10736 XOR»ïÇüÁ¦2 Gold III
// Constructive, ad_hoc
#include <iostream>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 101;
int N;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		int i = 1, k = 0;
		if (N == 1)
			cout << "1\n1\n";
		else if (N == 2)
			cout << "2\n1 2\n";
		else {
			bool flag = false;
			while (i < N) i <<= 1;
			if (i == N) {
				flag = true;
			}
			k = i / 4;
			i -= k;
			i--;
			cout << min(i, N) - k + 1 + flag << "\n";
			for (int j = k; j <= min(i, N); j++)
				cout << j << " ";
			if (flag)
				cout << N;
			cout << "\n";
		}
	}
	
}