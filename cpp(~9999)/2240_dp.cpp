// 220609 #2240 자두나무 Gold V
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
const int MAX = 1003;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int T,W,a[MAX],d[MAX][32];
int dp(int cur,int cnt){
    if(cnt>W)return -INF;
    if(cur>=T)return 0;
    int&ret=d[cur][cnt];
    if(~ret)return ret;
    ret=dp(cur+1,cnt);
    if(a[cur]!=cnt%2)ret=max(ret,dp(cur+1,cnt)+1);
    else ret=max(ret,dp(cur+1,cnt+1)+1);
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>T>>W;
    for(int i=0;i<T;i++){
        cin>>a[i];
        a[i]=a[i]%2;
    }
    memset(d,-1,sizeof(d));
    cout<<dp(0,0);
}