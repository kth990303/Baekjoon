// 210809 #11585 속타는 저녁 메뉴 Platinum V
// KMP, cicular string -> str + str
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 1000001;
int N;
string s, p;
int gcd(int a, int b) {
	int r = a % b;
	if (!r)return b;
	return gcd(b, r);
}
vector<int> fail() {
	int j = 0;
	vector<int> pi(p.length(), 0);
	for (int i = 1; i < p.length(); i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp() {
	vector<int> ret, pi = fail();
	int j = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == p.length() - 1) {
				ret.push_back(i - j + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string k;
		cin >> k;
		p += k;
	}
	for (int i = 0; i < N; i++) {
		string k;
		cin >> k;
		s += k;
	}
	s += s;
	int n = kmp().size();
	int r = gcd(n, N);
	n /= r; N /= r;
	cout << n << "/" << N << "\n";
}