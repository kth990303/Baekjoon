// 210214 #17609 회문 Silver I
// 구현, 투포인터 느낌
// 재귀로 더 간단히 풀 수 있는 듯 하다
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int check(string s) {
	// flag이면 회문, flag2이면 유사회문
	bool flag = true, flag2 = true;
	// del은 삭제 횟수
	int tmpi = 0, tmpj = 0, del = 0;
	for (int i = 0, j = 0;; i++, j++) {
		// 맞왜틀해서 추가한 코드
		if (i > s.length() - 1 - j)
			break;
		// 만약 일치하지 않는 문자가 나타난다면
		if (s[i] != s[s.length() - 1 - j]) {
			// 회문은 아니다
			flag = false;
			// 삭제를 2번 이상 했다면 유사회문도 아니다
			if (del==2) {
				flag2 = false;
				break;
			}
			// 삭제를 1번 했는데, 안맞는 경우가 나온다고
			// 바로 flag2=false로 하면 안된다.
			// 그 이유는 밑 else문에서 알 수 있다
			else if (del==1) {
				i = tmpi;
				j = tmpj;
				del++;
				if (s[i + 1] == s[s.length() - 1 - j]) {
					i++;
					continue;
				}
			}
			else {
				// 삭제를 해야 한다
				del++;
				// 만약 끝에서 j번째 문자를 삭제할 때
				// 문자가 일치한다면 그 경우를 삭제한다.

				// 근데 이 경우에서 일치한다 하더라도,
				// 이 경우로 진행하면 2번 이상 삭제해야 돼서 불가능하면서
				// i번째에서 삭제하는 게 유사회문이 가능한 경우가 있다
				// 따라서 이 경우가 실패할 경우, 그 밑의 else if문이 실행되도록 해야 한다.
				// 따라서 위에서 del==1일 때 처리해주는 코드가 있는 것.
				if (s[i] == s[s.length() - 1 - (j + 1)]) {
					tmpi = i;
					tmpj = j;
					j++;
					continue;
				}
				else if (s[i + 1] == s[s.length() - 1 - j]) {
					tmpi = i;
					tmpj = j;
					i++;
					continue;
				}
				// 둘 다 만족하지 않는다면 그냥 유사회문이 아닌 것
				flag2 = false;
				break;
			}
		}
	}
	if (flag)
		return 0;
	else if (flag2)
		return 1;
	return 2;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << check(s) << "\n";
	}
}