// 220505 #24955 숫자이어붙이기 Gold V
// BFS (unsigned long long type)
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1013;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,Q,a[MAX];
vector<int> v[MAX];
bool vis[MAX];
ll bfs(ll s,ll e){
    queue<pl> q;
    q.push({s,a[s]%MOD});
    vis[s]=true;
    while(!q.empty()) {
        ll cur=q.front().first;
        ll val=q.front().second;
        q.pop();
        if(cur==e)return val;
        for(ll i:v[cur]){
            if(vis[i])continue;
            vis[i]=true;
            q.push({i,stoull(to_string(val)+ to_string(a[i]))%MOD});
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>Q;
    for(int i=1;i<=N;i++)cin>>a[i];
    for(int i=0;i<N-1;i++){
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    for(int i=0;i<Q;i++){
        ll n1,n2;
        cin>>n1>>n2;
        fill(vis,vis+MAX,false);
        cout<<bfs(n1,n2)<<"\n";
    }
}