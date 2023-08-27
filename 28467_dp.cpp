#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 4e2+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX],d[MAX][MAX],d2[MAX][MAX];
pi dp(int s, int e) {
    int& ret=d[s][e];
    int& ret2=d2[s][e];
    if(s>e)return {INF,0};
    if(s==e)return {ret=0,ret2=a[e]};
    if(e==s+1)return {ret=a[s]+a[e], ret2=max(a[s],a[e])};
    if(~ret)return {ret,ret2};
    ret=INF;
    ret2=0;
    for (int i = s; i <= e; ++i) {
        int n=dp(s,i).first+dp(i+1,e).first+dp(s,i).second+dp(i+1,e).second;
        ret=min(ret,n);
        ret2=max({ret2, dp(s,i).second, dp(i+1,e).second});
    }
    return {ret, ret2};
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    memset(d,-1,sizeof(d));
    memset(d2,-1,sizeof(d2));
    cout<<dp(0,N-1).first;
}
