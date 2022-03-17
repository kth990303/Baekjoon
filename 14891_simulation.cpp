// 220317 #14891 톱니바퀴 Gold V
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
const int MAX = 103;
const int SIZE = 16;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int K,a[4][8],b[8],n,dir,ans;
int vis[4];
void rotation(int cur){
    if(!vis[cur])return;
    if(vis[cur]==1){
        for(int i=0;i<8;i++){
            b[i]=a[cur][(i+7)%8];
        }
    }
    else {
        for(int i=0;i<8;i++){
            b[i]=a[cur][(i+1)%8];
        }
    }
    for(int i=0;i<8;i++){
        a[cur][i]=b[i];
    }
}
void left(int cur, int d){
    vis[cur]=d;
    if(!cur)return;
    if(a[cur-1][2]!=a[cur][6])left(cur-1,-d);
}
void right(int cur, int d){
    vis[cur]=d;
    if(cur==3)return;
    if(a[cur+1][6]!=a[cur][2])right(cur+1,-d);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<4;i++){
        string s;
        cin>>s;
        for(int j=0;j<8;j++){
            a[i][j]=s[j]-'0';
        }
    }
    cin>>K;
    while(K--){
        fill(vis,vis+4,0);
        cin>>n>>dir;
        --n;
        left(n,dir);
        right(n,dir);
        for(int i=0;i<4;i++)rotation(i);
    }
    for(int i=0;i<4;i++){
        if(a[i][0])ans+=(1<<i);
    }
    cout<<ans;
}