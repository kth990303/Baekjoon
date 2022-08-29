// 220829 #16197 두 동전 Gold IV
// bfs with five dimension visit check array
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e1+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,ans=0;
struct Point{
    int x,y;
};
Point p[2];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
char a[MAX][MAX];
bool vis[MAX][MAX][MAX][MAX][12];
bool inside(Point pp){
    return pp.x>=0&&pp.x<M&&pp.y>=0&&pp.y<N;
}
int check(Point p1, Point p2){
    int cnt=0;
    if(inside(p1))cnt++;
    if(inside(p2))cnt++;
    return cnt;
}
int bfs(Point p1, Point p2){
    int ret=11;
    queue<pair<int,pair<Point, Point>>> q;
    q.push({0,{p1,p2}});
    vis[p1.y][p1.x][p2.y][p2.x][0]=true;
    while(!q.empty()){
        int cur=q.front().first;
        Point p1=q.front().second.first;
        Point p2=q.front().second.second;
        q.pop();
        if(cur>=ret)continue;
        for (int i = 0; i < 4; i++) {
            Point np1={p1.x+dx[i],p1.y+dy[i]};
            Point np2={p2.x+dx[i],p2.y+dy[i]};
            int flag= check(np1,np2);
            if(a[np1.y][np1.x]!='#'&&a[np2.y][np2.x]!='#'){
                if(flag==2){
                    if(!vis[np1.y][np1.x][np2.y][np2.x][cur+1]){
                        vis[np1.y][np1.x][np2.y][np2.x][cur+1]=true;
                        q.push({cur+1,{np1,np2}});
                    }
                }
                else if(flag==1){
                    ret=cur+1;
                }
            }
            if(a[np2.y][np2.x]!='#'&&a[np1.y][np1.x]=='#'){
                flag= check(p1,np2);
                if(flag==2){
                    if(!vis[p1.y][p1.x][np2.y][np2.x][cur+1]){
                        vis[p1.y][p1.x][np2.y][np2.x][cur+1]=true;
                        q.push({cur+1,{p1,np2}});
                    }
                }
                else if(flag==1){
                    ret=cur+1;
                }
            }
            if(a[np1.y][np1.x]!='#'&&a[np2.y][np2.x]=='#'){
                flag= check(np1,p2);
                if(flag==2){
                    if(!vis[np1.y][np1.x][p2.y][p2.x][cur+1]){
                        vis[np1.y][np1.x][p2.y][p2.x][cur+1]=true;
                        q.push({cur+1,{np1,p2}});
                    }
                }
                else if(flag==1){
                    ret=cur+1;
                }
            }
        }
    }
    return ret>10?-1:ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    int cnt=0;
    for (int i = 0; i < N; i++) {
        string s;
        cin>>s;
        for (int j = 0; j < M; j++) {
            a[i][j]=s[j];
            if(a[i][j]=='o'){
                p[cnt].x=j;
                p[cnt++].y=i;
            }
        }
    }
    ans=bfs(p[0],p[1]);
    cout<<(ans>10?-1:ans);
}