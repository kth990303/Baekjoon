// 240420 #31740 Split the SSHS 3 Gold IV
// treedp, dfs
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
int N,a[MAX],d[MAX],w,par[MAX];
vector<int> v[MAX],c[MAX];
bool vis[MAX];
void init(int cur){
    vis[cur]=true;
    for(auto i:v[cur]){
        if(vis[i])continue;
        par[i]=cur;
        c[cur].push_back(i);
        init(i);
    }
}
int dp(int cur){
    int& ret=d[cur];
    if(~ret)return ret;
    ret=a[cur];
    for(auto i:c[cur]){
        ret+=dp(i);
    }
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N - 1; ++i) {
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        w+=a[i];
    }
    init(1);
    memset(d,-1,sizeof(d));
    dp(1);
    int ans=INF,idx1=-1,idx2=-1;
    for (int i = 1; i <= N; ++i) {
        if(d[i]==-1)continue;
        int res=abs(w-2*d[i]);
        if(ans>res){
            ans=res;
            idx1=par[i];
            idx2=i;
        }
    }
    cout<<ans<<"\n"<<idx1<<" "<<idx2;
}
