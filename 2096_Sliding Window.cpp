// 200823 Sliding Window Algorithm
// #2096 Gold IV
// ����� dp�ϸ� �� ���� �޸� �ʰ�~
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
		// input�迭�� �Է� �����ְ�~
		for (int j = 0; j < 3; j++) {
			cin >> input[j];
		}
		// ó�� �Է� ���� �� �ٷ� dp�迭��
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				dpMax[j] = dpMin[j] = input[j];
			}
		}
		// ó�� �Է��� �ƴ� ���
		else {
			// dynamic programming
			// tmp�迭: ���������� ��� dp
			dpMax[0] = max(tmpMax[0], tmpMax[1]) + input[0];
			dpMax[1] = max(max(tmpMax[0], tmpMax[1]), tmpMax[2]) + input[1];
			dpMax[2] = max(tmpMax[1], tmpMax[2]) + input[2];
			// �ּҰ��� �����ְ�
			dpMin[0] = min(tmpMin[0], tmpMin[1]) + input[0];
			dpMin[1] = min(min(tmpMin[0], tmpMin[1]), tmpMin[2]) + input[1];
			dpMin[2] = min(tmpMin[1], tmpMin[2]) + input[2];
		}
		// �����̵� �������� �ٽ�! �������⵵ O(1)�� �ȴ�
		memcpy(tmpMax, dpMax, sizeof(tmpMax));
		memcpy(tmpMin, dpMin, sizeof(tmpMin));
	}
	// dpMax�� �ִ�, dpMin�� �ּ�
	sort(dpMax, dpMax + 3);
	sort(dpMin, dpMin + 3);
	cout << dpMax[2] << " " << dpMin[0];
}