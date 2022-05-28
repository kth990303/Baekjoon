// 220529 #20058 마법사 상어와 파이어스톰 Gold IV
// rotate_array_clockwise, bfs
// impl, simulation
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 67;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,Q,a[MAX][MAX],tmp[MAX][MAX],ans1,ans2;
bool melt[MAX][MAX],vis[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void rotate(int x,int y,int l){
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            tmp[i][j]=a[y+l-j-1][x+i];
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            a[y+i][x+j]=tmp[i][j];
        }
    }
}
void checkIce(int x,int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<N&&ny<N){
            if(a[ny][nx]>0)cnt++;
        }
    }
    if(cnt<3)melt[y][x]=true;
}
void bfs(int x,int y){
    queue<pi> q;
    q.push({x,y});
    vis[y][x]=true;
    int cnt=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        cnt++;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<N&&ny<N){
                if(!vis[ny][nx]&&a[ny][nx]>0){
                    vis[ny][nx]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    ans2=max(ans2,cnt);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>Q;
    N=(1<<N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }
    while(Q--){
        int l;
        cin>>l;
        l=(1<<l);
        for(int i=0;i<N;i+=l){
            for(int j=0;j<N;j+=l){
                rotate(j,i,l);
            }
        }
        memset(melt, false, sizeof(melt));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                checkIce(j,i);
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(melt[i][j])a[i][j]--;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]>0)ans1+=a[i][j];
            if(!vis[i][j]&&a[i][j]>0)bfs(j,i);
        }
    }
    cout<<ans1<<"\n"<<ans2;
}