// #1786 Ã£±â Gold I
// KMP
#include <iostream>
#include <string>
#include <vector>
//KMP algorithm 1786 practice
using namespace std;
string t, p;
vector<int> fail() {
	int j = 0;
	vector<int> pi(p.length(), 0);
	for (int i = 1; i < p.length(); i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp() {
	vector<int> v;
	vector<int> pi = fail();
	int j = 0;
	for (int i = 0; i < t.length(); i++) {
		while (j > 0 && t[i] != p[j]) {
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			if (j == p.length() - 1) {
				v.push_back(i - p.length() + 2);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return v;
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	getline(cin, t);
	getline(cin, p);
	auto cnt = kmp();
	cout << cnt.size() << "\n";
	for (auto i : cnt)
		cout << i << " ";
}