// 221207 #9944 N*M 보드 완주하기 Gold III
// brute-force
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 30+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,ans,K;
char a[MAX][MAX];
bool vis[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void solve(int x, int y, int flag, int cnt, int res){
    if(K==cnt){
        ans=min(ans,res);
        return;
    }
    bool can=true;
    int nx=x+dx[flag];
    int ny=y+dy[flag];
    if(flag>=0&&flag<4&&nx>=0&&ny>=0&&nx<M&&ny<N&&!vis[ny][nx]&&a[ny][nx]=='.'){
        vis[ny][nx]=true;
        solve(nx,ny,flag,cnt+1,res);
        vis[ny][nx]=false;
    }
    else can=false;
    if(!can) {
        for (int i = 0; i < 4; i++) {
            if(flag==i)continue;
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<M&&ny<N&&!vis[ny][nx]&&a[ny][nx]=='.'){
                vis[ny][nx]=true;
                solve(nx,ny,i,cnt+1,res+1);
                vis[ny][nx]=false;
            }
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    while(cin>>N>>M){
        if(!N)break;
        ans=INF;
        K=0;
        for (int i = 0; i < N; i++) {
            string s;
            cin>>s;
            for (int j = 0; j < M; j++) {
                a[i][j]=s[j];
                if(a[i][j]=='.')K++;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(a[i][j]=='*')continue;
                vis[i][j]=true;
                solve(j,i,-1,1,0);
                vis[i][j]=false;
            }
        }
        cout<<"Case "<<tc++<<": "<<(ans==INF?-1:ans)<<"\n";
    }
}