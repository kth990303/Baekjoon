// 200912 #1655 가운데를 말해요 Gold II
// 최소힙과 최대힙을 이용
// 웰논성이 짙은 것 같으므로 알아두자
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//최대 힙에는 a[N/2]이하의 작은 값들이
	//최소 힙에는 최대힙보다 큰 값들이
	//최대 힙의 가장 큰 원소 (top)이 중간값
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		// pq1에 넣어주기
		if (pq1.size() == pq2.size()) {
			pq1.push(k);
		}
		// pq1 사이즈가 더 큰 경우 pq2에 넣어주기
		else {
			pq2.push(k);
		}
		// pq2의 최소가 pq1의 최대보다 커야 됨
		// 같은 경우는 굳이 swap안해줘도됨
		if (!pq2.empty() && pq1.top() > pq2.top()) {
			int top1 = pq1.top();
			int top2 = pq2.top();
			pq1.pop();
			pq2.pop();
			pq1.push(top2);
			pq2.push(top1);
		}
		cout << pq1.top() << "\n";
	}
}