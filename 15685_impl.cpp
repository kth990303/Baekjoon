// 220824 #15685 드래곤 커브 Gold IV
// simulation
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
int vis[MAX][MAX],N;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int check(int x,int y){
    if(x+1>100||y+1>100||x<0||y<0)return 0;
    return(vis[y][x]&&vis[y][x+1]&&vis[y+1][x]&&vis[y+1][x+1])?1:0;
}
vector<pi> curve(vector<pi> v){
    vector<pi> ret=v;
    reverse(all(v));
    int X=v[0].first, Y=v[0].second;
    for (int i = 0; i < sz(v); i++) {
        if(!i)continue;
        int x=v[i].first;
        int y=v[i].second;
        // clockwise
        int cx=x-X;
        int cy=y-Y;
        int ccx=-cy;
        int ccy=cx;
        ret.push_back({X+ccx, Y+ccy});
    }
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    int ans=0;
    for (int i = 0; i < N; i++) {
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        vector<pi> v;
        v.push_back({x,y});
        v.push_back({x+dx[d],y+dy[d]});
        for (int j = 1; j <= g; j++) {
            v=curve(v);
        }
        for(auto i:v){
            int x=i.first;
            int y=i.second;
            if(x>=0&&y>=0&&x<=100&&y<=100)vis[y][x]++;
        }
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            ans+= check(j,i);
        }
    }
    cout<<ans;
}