// 221214 #16957 체스판 위의 공 Gold IV
// dp + graphs
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 5e2+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,a[MAX][MAX],d[MAX][MAX],ans[MAX][MAX];
int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={-1,-1,-1,0,1,1,1,0};
int move(int x,int y){
    int idx=-1,m=a[y][x];
    for (int i = 0; i < 8; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<M&&ny<N){
            if(a[ny][nx]<m){
                m=a[ny][nx];
                idx=i;
            }
        }
    }
    return idx;
}
int dp(int x, int y){
    int& ret=d[y][x];
    if(~ret)return ret;
    ret=0;
    int now=move(x,y);
    if(now==-1)return ret=y*M+x;
    else return ret=dp(x+dx[now],y+dy[now]);
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>a[i][j];
        }
    }
    memset(d,-1,sizeof(d));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int res=dp(j,i);
            ans[res/M][res%M]++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}