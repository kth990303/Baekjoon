// 210724 #17938 Æþ´çÆþ´ç2 Silver IV
// impl + math O(T)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 2011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, P, T;
bool visit[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> P >> T;
	ll hand = 0, dHand = 0;
	bool flag = false;
	N *= 2; P *= 2;
	for (int i = 1; i <= T; i++) {
		!flag ? ++dHand : --dHand;
		hand += dHand;
		if (dHand == N)
			flag = true;
		if (i != 1 && dHand == 1)
			flag = false;
	}
	int idx1 = ((hand - dHand + 1 + N) % N);
	int idx2 = (hand % N);
	int k = idx1 + dHand;
	for (int i = idx1; i < k; i++) {
		if (i > N)
			visit[i % N] = true;
		else
			visit[i] = true;
	}
	if (visit[(P - 1) % N] || visit[P % N])
		cout << "Dehet YeonJwaJe ^~^\n";
	else
		cout << "Hing...NoJam\n";
}