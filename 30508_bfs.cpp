// 231120 #30508 고인물이싫어 Gold V
// bfs + prefix_sum
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
int N,M,H,W,a[MAX][MAX],K;
vector<pi> v;
int vis[MAX][MAX],res[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void bfs(int y,int x){
    vis[y][x]=1;
    queue<pi> q;
    q.push({x,y});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||ny<1||nx>M||ny>N)continue;
            if(a[ny][nx]<a[y][x])continue;
            if(vis[ny][nx])continue;
            vis[ny][nx]=1;
            q.push({nx,ny});
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>H>>W;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin>>a[i][j];
        }
    }
    cin>>K;
    for (int i = 0; i < K; ++i) {
        int r,c;cin>>r>>c;
        bfs(r,c);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            res[i][j]=res[i][j-1]+res[i-1][j]-res[i-1][j-1]+vis[i][j];
        }
    }
    int ans=0;
    for (int i = H; i <= N; ++i) {
        for (int j = W; j <= M; ++j) {
            if(res[i][j]-res[i-H][j]-res[i][j-W]+res[i-H][j-W] == H*W)ans++;
        }
    }
    cout<<ans;
}
