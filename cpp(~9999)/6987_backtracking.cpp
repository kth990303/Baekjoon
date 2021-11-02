// 210111 #6987 ¿ùµåÄÅ Silver II
// backtracking
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 6;
int win[MAX], draw[MAX], lose[MAX];
// game match
int n1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int n2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
bool flag = false;
void solve(int cur) {
	// if cur can more 15, this game can do it
	if (cur == 15) {
		flag = true;
		return;
	}
	if (flag)
		return;
	// t1 win, t2 lose
	int t1 = n1[cur];
	int t2 = n2[cur];
	if (win[t1] > 0 && lose[t2] > 0) {
		win[t1]--; lose[t2]--;
		solve(cur + 1);
		win[t1]++; lose[t2]++;
	}
	// draw
	if (draw[t1] > 0 && draw[t2] > 0) {
		draw[t1]--; draw[t2]--;
		solve(cur + 1);
		draw[t1]++; draw[t2]++;
	}
	if (lose[t1] > 0 && win[t2] > 0) {
		lose[t1]--; win[t2]--;
		solve(cur + 1);
		lose[t1]++; win[t2]++;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) {
		flag = false;
		bool check = true;
		for (int j = 0; j < MAX; j++) {
			cin >> win[j] >> draw[j] >> lose[j];
			if (win[j] + draw[j] + lose[j] != 5) {
				check = false;
			}
		}
		if (check) {
			solve(0);
		}
		cout << flag << "\n";
	}
}