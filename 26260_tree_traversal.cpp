// 240316 #26260 이가빠진이진트리 Gold V
// graphs, tree_traversal, dfs
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,X,a[MAX],n,c[MAX];
bool vis[MAX];
vector<int> v[MAX];
void init(int idx, int cur, int k){
    c[cur]=idx;
    vis[cur]=true;
    for(auto i:v[cur]){
        if(!vis[cur*2])init(idx-k/2,cur*2,k/2);
        if(!vis[cur*2+1])init(idx+k/2,cur*2+1,k/2);
    }
}
void dfs(int cur){
    vis[cur]=true;
    if(v[cur].empty()){
        cout<<a[c[cur]+1]<<" ";
        return;
    }
    for(auto i:v[cur]){
        if(!vis[cur*2])dfs(cur*2);
        if(!vis[cur*2+1])dfs(cur*2+1);
    }
    cout<<a[c[cur]+1]<<" ";
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        if(a[i]==-1)n=i;
        if(i<=N/2){
            v[i].push_back(i*2);
            v[i].push_back(i*2+1);
        }
    }
    cin>>X;
    a[n]=X;
    sort(a+1,a+N+1);
    init(N/2,1,N/2+1);
    fill(vis,vis+N+1,false);
    dfs(1);
}
