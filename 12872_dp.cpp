// 220512 #12872 플레이리스트 Gold I
// dp
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
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,M,P,d[MAX][MAX];
ll dp(int cur, int music) {
    if(cur>=P)return music==N?1:0;
    ll& ret=d[cur][music];
    if(~ret)return ret;
    ret=0;
    ret+=dp(cur+1,music+1)*(N-music);
    ret%=MOD;
    if(music>=M)ret+=dp(cur+1,music)*(music-M);
    return ret%MOD;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>P;
    memset(d,-1,sizeof(d));
    cout<<dp(0,0);
}