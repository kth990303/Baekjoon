// 200913 #1484 다이어트 Gold III
// O(N^2)으론 안된다. 근데, 이 문제 G와 시간복잡도가 어떠한 관련이 있는지 아직은 감이 잘 안온다... 
// 이렇게 다 뒤져봐야되는데, O(N)-> 투포인터. 종료 조건이 수학적이다
#include <iostream>
using namespace std;
int G;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> G;
	// 자연수일 때부터, 시작부터 차분히 따져보기
	// 시작점=끝점=1이므로 자동으로 정답은 오름차순으로 출력됨
	int s = 1, e = 1;
	bool flag = false;	// false일 경우 -1
	while (1) {
		// 한 번이라도 정답인 경우 있으면 -1 출력할 일이 없음
		// 따라서 flag=true;
		if (e * e - s * s == G) {
			flag = true;
			cout << e << "\n";
			e++;
		}
		// 요구하는 답보다 큰 경우
		// 시작범위를 좁혀서(s를 키워서) 작게 만든다
		else if (e * e - s * s > G) {
			// 종료조건
			// 이 이후로는 어차피 e*e-s*s값이 G보다 무조건 크다
			if (e - s == 1)
				break;
			s++;
		}
		// 요구하는 답보다 작은경우
		else if (e * e - s * s < G) {
			e++;
		}
	}
	// 요구하는 답이 없을 경우 -1 출력
	if (!flag) {
		cout << -1 << "\n";
	}
}