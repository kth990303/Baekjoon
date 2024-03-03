// 240303 #17485 진우의 달여행 (Large)
// dp
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
int N,M,a[MAX][MAX],d[MAX][MAX][4];
int dp(int y, int x, int flag){
    if(y==N)return 0;
    int& ret=d[y][x][flag];
    if(~ret)return ret;
    ret=INF;
    if(flag!=1)ret=min(ret,dp(y+1,x,1));
    if(x>=1&&flag!=0)ret=min(ret,dp(y+1,x-1,0));
    if(x<M-1&&flag!=2)ret=min(ret,dp(y+1,x+1,2));
    return ret+=a[y][x];
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>a[i][j];
        }
    }
    int ans=INF;
    memset(d,-1,sizeof(d));
    for (int i = 0; i < M; ++i) {
        ans=min(ans,dp(0,i,3));
    }
    cout<<ans;
}
