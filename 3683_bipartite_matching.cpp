// 211021 #3683 고양이와개 Platinum III
// bipartite_matching
// maximum independent set = V - bipartite_matching
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 503;
const int INF = 0x3f3f3f3f;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int t, C, D, V, d[MAX];
vector<int> v[MAX];
vector<pi> cat, dog;
bool used[MAX];
bool dfs(int cur) {
    for (auto i : v[cur]) {
        if (used[i])
            continue;
        used[i] = true;
        if (d[i] == -1 || dfs(d[i])) {
            d[i] = cur;
            return true;
        }
    }
    return false;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cat.clear(); dog.clear();
        for (int i = 0; i < MAX; i++) {
            v[i].clear();
            d[i] = -1;
        }
        cin >> C >> D >> V;
        for (int i = 0; i < V; i++) {
            string a, b;
            cin >> a >> b;
            if (a[0] == 'C') 
                cat.push_back({ stoi(a.substr(1)), stoi(b.substr(1)) });
            else
                dog.push_back({ stoi(a.substr(1)), stoi(b.substr(1)) });
        }
        for (int i = 0; i < cat.size(); i++) {
            for (int j = 0; j < dog.size(); j++) {
                if (cat[i].first == dog[j].second ||
                    cat[i].second == dog[j].first) {
                    v[i].push_back(j + cat.size() + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < cat.size(); i++) {
            fill(used, used + MAX, false);
            if (dfs(i))
                res++;
        }
        cout << V - res << "\n";
    }
}