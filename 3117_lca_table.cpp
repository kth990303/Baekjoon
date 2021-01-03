// 210103 #3117 YouTube Platinum V
// sparse table (lca_table) (Standard)
// like #17435
// O(NlgM)
#include <iostream>
using namespace std;
const int MAX = 100001;
const int SIZE = 30;
int N, M, K, d[MAX], p[MAX][SIZE];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= K; i++) {
		cin >> p[i][0];
	}
	for (int j = 1; j < SIZE; j++) {
		for (int i = 1; i <= K; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];	
		}
	}
	for (int i = 1; i <= N; i++) {
		int n = M - 1;
		int x = d[i];
		for (int j = SIZE - 1; j >= 0; j--) {
			if (n >= (1 << j)) {
				n -= 1 << j;
				x = p[x][j];
			}
		}
		//64ms
		cout << x << " ";
		//d[i] = x;
	}
	/*
	68ms
	for (int i = 1; i <= N; i++) {
		cout << d[i] << " ";
	}
	*/
}