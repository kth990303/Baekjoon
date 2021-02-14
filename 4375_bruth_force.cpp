// 210214 #4375 1 Silver III
// Bruth-Force
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 10001;
ll N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	// 왜 string으로 하면 런타임 에러가 뜨는지 모르겠다
	while (cin >> N) {
		// n은 N으로 나눈 나머지.
		ll n = 1 % N;
		for (int i = 1;; i++) {
			// 나머지가 0이면 배수인 셈
			if (!n) {
				cout << i << "\n";
				break;
			}
			// 1을 이어서 붙여서 %N을 구해준다.
			n *= 10;
			n++;
			n %= N;
		}
	}
}