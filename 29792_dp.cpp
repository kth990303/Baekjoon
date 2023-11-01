// 231101 #29792 규칙적인보스돌이 Gold V
// dp, brute_force, greedy
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 50+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,K,p[MAX],q[MAX],d[MAX][903],damage;
int dp(int cur, int sec){
    if(cur>=K || sec<=0)return 0;
    int& ret=d[cur][sec];
    if(~ret)return ret;
    ret=0;
    ret=dp(cur+1,sec);
    int t=p[cur]/damage;
    if(p[cur]%damage)t++;
    if(sec-t>=0)ret=max(ret,dp(cur+1,sec-t)+q[cur]);
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        int n;cin>>n;
        pq.push(n);
    }
    for (int i = 0; i < K; ++i) {
        cin>>p[i]>>q[i];
    }
    int cnt=M,ans=0;
    while(cnt--) {
        damage=pq.top();
        pq.pop();
        memset(d,-1,sizeof(d));
        ans+=dp(0,900);
    }
    cout<<ans;
}
