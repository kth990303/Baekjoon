#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a;
int b;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b;
	int ans = -1;
	sort(a.begin(), a.end());
	// a���� ���� �� ������ �� (9!�� �ð����⵵)
	do {
		if (a[0] == '0')
			continue;
		int num = stoi(a);
		if (num < b) {
			ans = max(ans, num);
		}
		
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << "\n";
}