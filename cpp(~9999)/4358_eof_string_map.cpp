// 200904 #4358 ������ Gold IV
// Trie �����Ϸ� �ߴµ� �׳� map���� �ع���...
// map, �Ҽ��� ���ڸ�, eof ���������� ġ��
// ������ �� trie�� �غ���
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while (getline(cin, s)) {
		m[s]++;
		N++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " " << 
			(double)((double)(*it).second / N) * 100 << "\n";
	}
}