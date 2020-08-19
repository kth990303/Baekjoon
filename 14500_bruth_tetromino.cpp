// 200819 Bruth-force #14500 Gold V
// ��¥ ���밡��...���Ʈ ������ ��ǥ�� �� �� ���� ������
// ��û�� �밡��...
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
	// ���簢��
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
	// �� ���簢�� (2����)
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
	// ���� (8����)
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
	// ���� (4����)
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
	// �Ǹ�� (4����)
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