// 220311 #14863 서울에서 경산까지 Gold IV
// 넣지 않는 경우가 존재하기 때문에 결국은 knapsack이 아닌 2차원 dp
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,K,d[MAX][100003],a[2][MAX],w[2][MAX];
int dp(int cur, int t){
    if(cur>=N)return 0;
    int& ret=d[cur][t];
    if(~ret)return ret;
    ret=-INF;
    if(t>=a[0][cur]){
        ret=max(ret, dp(cur+1,t-a[0][cur])+w[0][cur]);
    }
    if(t>=a[1][cur]){
        ret=max(ret, dp(cur+1, t-a[1][cur])+w[1][cur]);
    }
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            cin>>a[j][i]>>w[j][i];
        }
    }
    memset(d,-1,sizeof(d));
    cout<<dp(0,K);
}