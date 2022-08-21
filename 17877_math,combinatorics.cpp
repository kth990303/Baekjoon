// 220821 #17877 Integer Division Silver II
// map, combinatorics
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,D,a[MAX];
    cin>>N>>D;
    map<int,int> m;
    for (int i = 0; i < N; i++) {
        cin>>a[i];
        m[a[i]/D]++;
    }
    int ans=0;
    for (auto it = m.begin(); it != m.end(); it++) {
        int n=it->second;
        ans+=n*(n-1)/2;
    }
    cout<<ans;
}