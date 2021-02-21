// 210221 #18294 Biodiversity Silver III
// DS_map 문제를 잘 읽자. 
// similar of #1302, but different question
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> m;
int N;
string s, ans;
bool flag = true;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s]++;
		if (N/2 < m[s]) {
			ans = s;
			flag = false;
		}
	}
	if (flag)
		cout << "NONE\n";
	else
		cout << ans << "\n";
}