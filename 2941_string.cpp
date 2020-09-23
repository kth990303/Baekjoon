// 200923 #2941 크로아티아 알파벳 Silver V
// C++은 왜 python의 replace 기능이 없을까
// 다음 업데이트땐 생기길
#include <iostream>
#include <string>
using namespace std;
string words[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s, tmp;
	cin >> s;
	int cnt = 0;
	int ans = s.length();
	for (int i = 0; i < s.length(); i++) {
		tmp += s[i];
		// 주어진 words 배열은 8가지
		for (int j = 0; j < 8; j++) {
			bool flag = true;
			for (int k = 0; k < words[j].length(); k++) {
				// 길이가 words[j]보다 짧으면
				// 런타임에러 방지를 위해 break
				if (tmp.length() < words[j].length()) {
					flag = false;
					break;
				}
				// 뒤에서부터 순차적으로 비교
				// tmp랑 다 비교하면 크로아티아 알파벳인데 못세는 경우 존재
				if (tmp[tmp.length() - 1 - k] != words[j][words[j].length() - k - 1]) {
					flag = false;
					break;
				}
			}
			// 맞을 경우 크로아티아 알파벳 길이만큼 빼주고
			if (flag) {
				cnt++;
				ans -= words[j].length();
				tmp = "";
				break;
			}
		}
	}
	// 크로아티아 알파벳만큼 더함
	cout << ans + cnt << "\n";
}