// 200926 #2108 ����� Silver IV
// �ݿø�, �ֺ� ���� �� ��ٷο� ����
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 8001;
int used[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> v(N);
	double sum = 0;
	int max_cnt = 0;	// �ֺ� ����
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
		used[v[i] + 4000]++;
		max_cnt = max(max_cnt, used[v[i] + 4000]);
	}
	sort(v.begin(), v.end());

	// VS�� ������ ��  ������ ������ �ٸ�
	// -5/2�� �ݿø��ϸ� -3. �ٵ� VS���� -2�� ó����
	if (sum > 0)
		cout << (int)((sum / (double)(N)) + 0.5) << "\n";
	else
		cout << (int)((sum / (double)(N)) - 0.5) << "\n";
	// �߾Ӱ�
	cout << v[N / 2] << "\n";
	// �ֺ�
	vector<int> v2;
	for (int i = 0; i < MAX; i++) {
		if (used[i] == max_cnt)
			v2.push_back(i-4000);	// 0~8000
	}
	sort(v2.begin(), v2.end());
	if (v2.size() == 1)
		cout << v2[0] << "\n";
	// �ι�°�� ���� ��
	else
		cout << v2[1] << "\n";
	// ����
	cout << v[v.size() - 1] - v[0] << "\n";
}