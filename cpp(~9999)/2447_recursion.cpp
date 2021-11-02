// 201212 #2447 별찍기-10 Silver I
// 재귀에 대한 이해 외에 코드 구현력, 재귀 응용이 필요함.
// 재귀가 무려 9방향.
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N;
const int MAX = 6561;
char map[MAX][MAX];	// "\n"처리때문에 따로 배열에 저장
void solve(int x, int a, int b) {
	if (x == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					map[a + i][b + j] = ' ';
				else
					map[a + i][b + j] = '*';
			}
		}
		return;
	}
	// 재귀가 9방향으로 나누어져 있는데 방향성이 있다
	// 그럼 바로 for문을 써봐야겠다
	// 단, 가운데는 재귀를 하지 않는다.
	// 가운데를 어떻게 처리할까? 가운데일 때만 ' '를 넣는 방법도 있으나
	// 애초에 초기화를 ' '로 시키면 되지.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			solve(x / 3, a + x * i / 3, b + x * j / 3);
		}
	}
	
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	memset(map, ' ', sizeof(map));
	solve(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}