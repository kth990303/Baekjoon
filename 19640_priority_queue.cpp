// 210619 #19640 화장실의 규칙 Gold V
// priority_Queue + operator overloading + queue
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, K;
struct Person {
	int idx, d, h;
	bool flag;
};
Person p[MAX];
struct cmp {
	bool operator()(Person p1, Person p2) {
		if (p1.d != p2.d)
			return p1.d < p2.d;
		if (p1.h != p2.h)
			return p1.h < p2.h;
		return p1.idx > p2.idx;
	}
};
queue<Person> q[MAX];
priority_queue<Person, vector<Person>, cmp> pq;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		p[i].idx = i % M;
		cin >> p[i].d >> p[i].h;
		if (i == K)
			p[i].flag = true;
		else
			p[i].flag = false;
		q[i % M].push(p[i]);
	}
	for (int i = 0; i < M; i++) {
		if (q[i].empty())
			continue;
		pq.push(q[i].front());
		q[i].pop();
	}
	int cnt = 0;
	while (1) {
		Person now = pq.top();
		pq.pop();
		if (now.flag)
			break;
		cnt++;
		if (!q[now.idx].empty()) {
			pq.push(q[now.idx].front());
			q[now.idx].pop();
		}
	}
	cout << cnt << "\n";
}