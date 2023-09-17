// 230917 #29704 벼락치기 Gold V
// knapsack dp
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e3+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,T,d[MAX],a[MAX],b[MAX],ans;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>T;
    for (int i = 0; i < N; ++i) {
        cin>>a[i]>>b[i];
        ans+=b[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = T; j >= 1; --j) {
            if(j<a[i])continue;
            d[j]=max(d[j], d[j-a[i]]+b[i]);
        }
    }
    cout<<ans-d[T];
}
