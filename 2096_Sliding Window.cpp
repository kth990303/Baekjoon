// 200823 Sliding Window Algorithm
// #2096 Gold IV
// 평범한 dp하면 딱 봐도 메모리 초과~
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, dpMax[3] = { 0 }, dpMin[3] = { 0 },
		input[3] = { 0 }, tmpMax[3] = { 0 }, tmpMin[3] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		// input배열에 입력 때려넣고~
		for (int j = 0; j < 3; j++) {
			cin >> input[j];
		}
		// 처음 입력 받을 땐 바로 dp배열로
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				dpMax[j] = dpMin[j] = input[j];
			}
		}
		// 처음 입력이 아닐 경우
		else {
			// dynamic programming
			// tmp배열: 이전까지의 결과 dp
			dpMax[0] = max(tmpMax[0], tmpMax[1]) + input[0];
			dpMax[1] = max(max(tmpMax[0], tmpMax[1]), tmpMax[2]) + input[1];
			dpMax[2] = max(tmpMax[1], tmpMax[2]) + input[2];
			// 최소값도 구해주고
			dpMin[0] = min(tmpMin[0], tmpMin[1]) + input[0];
			dpMin[1] = min(min(tmpMin[0], tmpMin[1]), tmpMin[2]) + input[1];
			dpMin[2] = min(tmpMin[1], tmpMin[2]) + input[2];
		}
		// 슬라이딩 윈도우의 핵심! 공간복잡도 O(1)이 된다
		memcpy(tmpMax, dpMax, sizeof(tmpMax));
		memcpy(tmpMin, dpMin, sizeof(tmpMin));
	}
	// dpMax중 최대, dpMin중 최소
	sort(dpMax, dpMax + 3);
	sort(dpMin, dpMin + 3);
	cout << dpMax[2] << " " << dpMin[0];
}