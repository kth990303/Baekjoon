// 200902 #2473 �� ��� Gold IV
// #2467 ����� ���׷��̵� ����
// ��������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;	// 30�� �Ѵ� �ɷ� ��ƾߵ�
int N;
ll ans1, ans2, ans3;
vector<ll> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll sum = INF;
	// 1��°: �ǿ���
	for (int i = 0; i < N - 2; i++) {
		int s = i + 1;	// 2��°: 1��°���� ū�ź���
		int e = N - 1;	// 3��°: �� ����������
		while (1) {
			// ���� Ž�� ����
			if (s == e)
				break;
			if (abs(v[i] + v[s] + v[e]) < sum) {
				ans1 = v[i];
				ans2 = v[s];
				ans3 = v[e];
				sum = (ll)abs(v[i] + v[s] + v[e]);
			}
			// 24��° �ٿ� sort�� �������Ƿ�
			if (v[i] + v[s] + v[e] > 0)
				e--;
			else
				s++;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << "\n";
}