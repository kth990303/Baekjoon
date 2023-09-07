// 230907 #27211 도넛행성 Gold V
// bfs modulo exception handling
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
int N,M,a[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool vis[MAX][MAX];
pi np(pi p){
    if(p.first<0)return {N+p.first,p.second};
    if(p.first>=N)return {p.first-N,p.second};
    if(p.second<0)return  {p.first,M+p.second};
    if(p.second>=M)return {p.first,p.second-M};
    return {p.first,p.second};
}
void bfs(int y,int x){
    queue<pi> q;
    q.push({x,y});
    vis[y][x]=true;
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pi nxt=np({y+dy[i],x+dx[i]});
            int nx=nxt.second;
            int ny=nxt.first;
            if(a[ny][nx])continue;
            if(vis[ny][nx])continue;
            vis[ny][nx]=true;
            q.push({nx,ny});
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>a[i][j];
        }
    }
    int ans=0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(a[i][j])continue;
            if(vis[i][j])continue;
            ans++;
            bfs(i,j);
        }
    }
    cout<<ans;
}
