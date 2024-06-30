// 240630 #31946 죽음의 등굣길 S1
// bfs
// https://www.acmicpc.net/problem/31946
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e2+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t,N,M,a[MAX][MAX],X,n;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool vis[MAX][MAX];
void bfs() {
    queue<pi> q;
    vis[0][0]=true;
    q.push({0,0});
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(y==N-1&&x==M-1){
            cout<<"ALIVE";
            exit(0);
        }
        for(int i=-X;i<=X;i++){
            for(int j=-X;j<=X;j++){
                int nx=x+j;
                int ny=y+i;
                if(nx<0||ny<0||nx>=M||ny>=N)continue;
                if(abs(nx-x)+abs(ny-y)>X)continue;
                if(vis[ny][nx])continue;
                if(a[ny][nx]==n){
                    vis[ny][nx]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>a[i][j];
            if(i==0&&j==0)n=a[i][j];
        }
    }
    cin>>X;
    if(n!=a[N-1][M-1]){
        cout<<"DEAD";
        return 0;
    }
    bfs();
    cout<<"DEAD";
}
