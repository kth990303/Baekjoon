// 200819 Bruth-force #14500 Gold V
// 진짜 개노가다...브루트 포스의 대표라 할 수 있을 정도로
// 엄청난 노가다...
#include <iostream>
#include <algorithm>
using namespace std;
int a[501][501];
int N, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
		}
	}
	// 정사각형
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			for (int p = i; p <= i + 1; p++) {
				for (int q = j; q <= j + 1; q++) {
					sum += a[p][q];
				}
			}
			ans = max(sum, ans);
		}
	}
	// 긴 직사각형 (2가지)
	for (int i = 1; i <= N-3; i++) {
		for (int j = 1; j <= M; j++) {
			int sum = 0;
			for (int p = i; p <= i + 3; p++) {
				for (int q = j; q <= j; q++) {
					sum += a[p][q];
				}
			}
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M-3; j++) {
			int sum = 0;
			for (int p = i; p <= i; p++) {
				for (int q = j; q <= j+3; q++) {
					sum += a[p][q];
				}
			}
			ans = max(sum, ans);
		}
	}
	// ㄱ자 (8가지)
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M-1; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i][j + 1];
			sum += a[i + 1][j + 1];
			sum += a[i + 2][j + 1];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i][j+1];
			sum += a[i][j];
			sum += a[i + 1][j];
			sum += a[i + 2][j];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i][j + 1];
			sum += a[i + 1][j + 1];
			sum += a[i + 2][j + 1];
			sum += a[i + 2][j];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i+2][j + 1];
			sum += a[i][j];
			sum += a[i + 1][j];
			sum += a[i + 2][j];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i][j+1];
			sum += a[i][j+2];
			sum += a[i+1][j];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i][j + 1];
			sum += a[i][j + 2];
			sum += a[i + 1][j + 2];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i+1][j];
			sum += a[i+1][j + 1];
			sum += a[i+1][j + 2];
			sum += a[i][j];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i + 1][j];
			sum += a[i + 1][j + 1];
			sum += a[i + 1][j + 2];
			sum += a[i][j+2];
			ans = max(sum, ans);
		}
	}
	// ㄹ자 (4가지)
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i][j + 1];
			sum += a[i + 1][j + 1];
			sum += a[i+1][j+2];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i][j+2];
			sum += a[i][j + 1];
			sum += a[i + 1][j + 1];
			sum += a[i+1][j];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i + 1][j];
			sum += a[i + 1][j+1];
			sum += a[i+2][j+1];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i][j+1];
			sum += a[i + 1][j + 1];
			sum += a[i + 1][j];
			sum += a[i+2][j];
			ans = max(sum, ans);
		}
	}
	// ㅗ모양 (4가지)
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i][j + 1];
			sum += a[i][j + 2];
			sum += a[i+1][j+1];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i][j+1];
			sum += a[i+1][j + 1];
			sum += a[i+1][j];
			sum += a[i + 2][j + 1];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int sum = 0;
			sum += a[i+1][j];
			sum += a[i][j + 1];
			sum += a[i+1][j + 2];
			sum += a[i + 1][j + 1];
			ans = max(sum, ans);
		}
	}
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int sum = 0;
			sum += a[i][j];
			sum += a[i + 1][j + 1];
			sum += a[i + 1][j];
			sum += a[i + 2][j];
			ans = max(sum, ans);
		}
	}
	cout << ans;
}