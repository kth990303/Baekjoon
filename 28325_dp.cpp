// 230730 #28325 호숫가의 개미굴 Gold V
// dp || greedy
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 25e4+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX],d[MAX][2],ans;
vector<int> v;
int dp(int cur, int flag){
    if(cur>N)return 0;
    if(cur==N && flag)return 0;
    int& ret=d[cur][flag];
    if(~ret)return ret;
    if(a[cur])return ret=dp(cur+1, flag);
    ret=0;
    ret+=max(dp(cur+2, cur==1?1:flag)+1, dp(cur+1, flag));
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    v.push_back(0);
    for (int i = 1; i <= N; i++) {
        cin>>a[i];
        ans+=a[i];
    }
    a[N+1]=a[1];
    memset(d,-1,sizeof(d));
    cout<<ans+dp(1,0);
}