// 201226 #1120 문자열 Silver IV
// 문자열 + 그리디(Silver V) + 구현(+1)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	if (a.length() > b.length())
		swap(a, b);
	int ans = INF;
	// a가 무조건 짧은 문자열이 되므로
	// 그리고 a, b의 문자열 길이는 최대 50일 뿐이므로
	// a를 한칸씩 이동시키면서 a의끝까지 비교

	// 다만, 길이는 서로 같아야하므로 a의 끝과 b의 끝이 같아지는 시점까지만
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;	// 다른 개수
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j])
				cnt++;
		}
		// 더 적은 값으로 답 갱신
		ans = min(ans, cnt);
	}
	cout << ans << "\n";
}