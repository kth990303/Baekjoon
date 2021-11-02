// 201212 #6603 �ζ� Silver II
// ���, ��Ʈ��ŷ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 14;
int N, a[MAX];
vector<int> v;
bool visit[MAX];
void solve(int cur) {
	if (v.size() == 6) {
		sort(v.begin(), v.end());
		for (auto i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}
	// i=0���� ���� ��, 1 2 3 4 6 5 ��� ����.
	// �׷��� �� ������, ���� ��� ���� ����.
	for (int i = cur; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(a[i]);
			// solve(cur+1)�� �ƴ� solve(i+1)�� �ؾ� ��.
			solve(i + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
	
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) break;
		v.clear();
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		solve(0);
		cout << "\n";
	}
}