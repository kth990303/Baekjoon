// 210208 #2161 Ä«µå1 Bronze II
// implementation
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, a[MAX*10];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		a[i] = i;
	}
	int t = 1;
	while (N != 1) {
		cout << a[t] << " ";
		t++; N--;
		a[t + N] = a[t];
		t++;
	}
	cout << a[t] << "\n";
}