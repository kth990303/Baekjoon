// 220614 #14927 전구끄기 Platinum IV
// greedy, brute_force
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 20;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int dx[5]={0,0,-1,1,0};
int dy[5]={-1,1,0,0,0};
int N,a[MAX][MAX],ori[MAX][MAX],ans=INF;
void copy(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            a[i][j]=ori[i][j];
        }
    }
}
void click(int x,int y){
    for(int i=0;i<5;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=N&&ny<=N){
            a[ny][nx]=1-a[ny][nx];
        }
    }
}
bool check() {
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(a[i][j])return false;
        }
    }
    return true;
}
void solve(int num){
    int cnt=0;
    for(int j=1;j<=N;j++){
        if(num&(1<<(j-1))){
            click(j,1);
            cnt++;
        }
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<=N;j++){
            if(a[i][j]){
                click(j,i+1);
                cnt++;
            }
        }
    }
    if(check()) {
        ans = min(ans, cnt);
        return;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>ori[i][j];
        }
    }
    for(int i=0;i<(1<<N);i++){
        copy();
        solve(i);
    }
    cout<<(ans==INF?-1:ans);
}