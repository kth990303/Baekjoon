// 200909 #13418 학교 탐방하기 Gold III
// MST를 두 번해서 해결.
// 한 번해서 해결되는 풀이도 있지만 시중에 널려있을 거 같으니까
// 난 이대로 커밋할래
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, M, cnt1, cnt2;	// 오르막길 개수
int p[MAX];
vector<pair<int, pair<int, int>>> bestV, worstV;
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M + 1; i++) {
		int a, b, ch;
		cin >> a >> b >> ch;
		// best가 최악이다... 반대로 됐다...
		// 오르막길이 1인줄 알았다...
		bestV.push_back({ ch, {a,b} });
		// worst가 최선임... 암튼 !ch 하면 반대로 sort 되니까
		worstV.push_back({ !ch, {a,b} });
	}
	sort(bestV.begin(), bestV.end());
	sort(worstV.begin(), worstV.end());
	// 최악의 경우(...) 구하기
	for (int i = 0; i < bestV.size(); i++) {
		int node1 = bestV[i].second.first;
		int node2 = bestV[i].second.second;
		int cost = bestV[i].first;
		if (merge(node1, node2)) {
			if (!cost)
				cnt1++;
		}
	}
	// 최선의 경우 구하기
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}
	for (int i = 0; i < worstV.size(); i++) {
		int node1 = worstV[i].second.first;
		int node2 = worstV[i].second.second;
		int cost = worstV[i].first;
		if (merge(node1, node2)) {
			if (cost) {
				cnt2++;
			}
		}
	}
	// 교훈: 문제를 잘읽자
	cout << cnt1 * cnt1 - cnt2 * cnt2 << "\n";
}