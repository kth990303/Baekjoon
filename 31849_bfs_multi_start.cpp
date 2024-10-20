// 240604 #31849 편세권 Gold V
// https://www.acmicpc.net/problem/31849
// queue 에 시작점들을 미리 집어넣어서 1번의 bfs 로 푸는 아이디어
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
int N,M,R,C,p[MAX][MAX],flag[MAX][MAX],ans=INF;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool vis[MAX][MAX];
queue<pii> q;
void bfs() {
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int cost=q.front().first;
        q.pop();
        if(flag[y][x]==1)ans=min(ans,p[y][x]*cost);
        for (int i = 0; i < 4; ++i) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nCost=flag[ny][nx]==2?0:cost+1;
            if(vis[ny][nx])continue;
            if(nx>=1&&ny>=1&&nx<=M&&ny<=N){
                vis[ny][nx]=true;
                q.push({nCost,{nx,ny}});
            }
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>R>>C;
    for (int i = 0; i < R; ++i) {
        int y,x,c;cin>>y>>x>>c;
        p[y][x]=c;
        flag[y][x]=1;
    }
    for (int i = 0; i < C; ++i) {
        int y,x;cin>>y>>x;
        flag[y][x]=2;
        q.push({0,{x,y}});
        vis[y][x]=true;
    }
    bfs();
    cout<<ans;
}
