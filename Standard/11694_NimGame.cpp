// 200903 #11694 Nim Game Platinum III
// 에타에 재밌다길래 해봤는데 어렵기만 함 ㅠㅠ
// 님 합이 0이면 지고 0이 아니면 이김
// 이 경우는 베스킨라빈스처럼 마지막에 가져오는 사람이 지므로
// 좀 더 까다로움.
#include <iostream>
using namespace std;
const int MAX = 101;
int N, p[MAX], ans;
int xorRet() {
	for (int i = 1; i <= N; i++) {
		ans ^= p[i];
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int cnt = 0;	// 돌이 1개인 더미의 개수
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		// 돌이 1개인 더미의 개수를 세야 함.
		if (p[i] == 1)
			cnt++;
	}
	// 돌이 1개인 더미만으로 돼있을 때 예외처리 해주기
	if (cnt == N) {
		if (!(cnt % 2))
			cout << "koosaga" << "\n";
		else
			cout << "cubelover" << "\n";
		return 0;
	}
	// 돌이 1개인 더미가 짝수개일 때, 홀수개로 만들어주기
	if (!(cnt % 2) && cnt != 0) {
		for (int i = 1; i <= N; i++) {
			if (p[i] != 1) {
				p[i] = 1;
				break;
			}
		}
	}
	// 님의 합 0이면 후공, 0이 아니면 선공해서 0으로 만들어버리기~
	if (!xorRet())
		cout << "cubelover" << "\n";
	else
		cout << "koosaga" << "\n";
}