// 221107 #1106 호텔 Gold V
// minimum knapsack
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e3+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int C,N,d[MAX],c[21],k[21],ans=INF;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>C>>N;
    for (int i = 0; i < N; i++) {
        cin>>c[i]>>k[i];
    }
    fill(d,d+MAX,INF);
    d[0]=0;
    for (int i = 0; i < N; i++) {
        for (int j = k[i]; j <= C+k[i]; j++) {
            d[j]=min(d[j], d[j-k[i]]+c[i]);
            if(j>=C)ans=min(ans,d[j]);
        }
    }
    cout<<ans;
}