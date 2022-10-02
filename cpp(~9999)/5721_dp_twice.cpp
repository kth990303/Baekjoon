// 221002 #5721 사탕줍기대회 Gold IV
// dp -> garo, sero twice dp
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t,N,M;
vector<vector<int>> a;
vector<int> k, d,d2;
int dp(int y, int x){
    if(x>=M)return 0;
    int&ret=d2[x];
    if(~ret)return ret;
    ret=0;
    ret=max({dp(y,x+2)+a[y][x], dp(y,x+3)+a[y][x], dp(y,x+1)});
    return ret;
}
int solve(int y){
    if(y>=N)return 0;
    int& ret=d[y];
    if(~ret)return ret;
    ret=0;
    ret=max({solve(y+2)+k[y], solve(y+3)+k[y], solve(y+1)});
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        cin>>N>>M;
        if(!N&&!M)break;
        for(auto& i:a)i.clear();
        k.clear(); d.clear();d2.clear();
        k.resize(N);a.resize(N);d.resize(N);d2.resize(M);
        for (int i = 0; i < N; i++) {
            a[i].resize(M);
            d[i]=-1;
            for (int j = 0; j < M; j++) {
                cin>>a[i][j];
                d2[j]=-1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                d2[j]=-1;
            }
            k[i]=dp(i,0);
        }
        cout<<solve(0)<<"\n";
    }
}