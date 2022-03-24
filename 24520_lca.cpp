// 220325 #24520 meet in the middle Platinum IV
// lca + sparse_table
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e5+3;
const int SIZE = 17;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,K,d[MAX],p[MAX][SIZE + 1],dis[MAX],dist,idx;
vector<pl> v[MAX];
bool vis[MAX];
void init(int cur) {
    for (auto i : v[cur]) {
        if (d[i.second] == -1) {
            d[i.second] = d[cur] + 1;
            p[i.second][0] = cur;
            dis[i.second]=dis[cur]+i.first;
            init(i.second);
        }
    }
}
ll lca(int a, int b) {
    if (d[a] < d[b])
        swap(a, b);
    ll diff = d[a] - d[b];
    int j = 0;
    while (diff) {
        if (diff % 2)
            a = p[a][j];
        diff /= 2;
        j++;
    }
    if (a == b)
        return a;
    for (int j = SIZE; j >= 0; j--) {
        if (p[a][j] != -1 && p[a][j] != p[b][j]) {
            a = p[a][j];
            b = p[b][j];
        }
    }
    a = p[a][0];
    return a;
}
ll solve(ll s, ll e){
    while(s<=e){
        ll mid=(s+e)/2;
        if(p[idx][mid]==-1){
            return solve(s,mid-1);
        }
        ll distance=dis[idx]-dis[p[idx][mid]];
        if(distance==dist)return p[idx][mid];
        else if(distance<dist){
            idx=p[idx][mid];
            dist-=distance;
            return solve(0,e);
        }
        else return solve(s,mid-1);
    }
    return -1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;
    for(int i=0;i<N-1;i++){
        ll n1,n2,cost;
        cin>>n1>>n2>>cost;
        v[n1].push_back({cost,n2});
        v[n2].push_back({cost,n1});
    }
    memset(p, -1, sizeof(p));
    fill(d, d + MAX, -1);
    d[1]=0;
    init(1);
    for (int j = 0; j < SIZE; j++) {
        for (int i = 1; i <= N; i++) {
            if (p[i][j] != -1)
                p[i][j + 1] = p[p[i][j]][j];
        }
    }
    while(K--){
        int n1,n2;
        cin>>n1>>n2;
        int node=lca(n1,n2);
        ll dist1=dis[n1]-dis[node];
        ll dist2=dis[n2]-dis[node];
        if(dist1==dist2){
            cout<<node<<"\n";
            continue;
        }
        if((dist1+dist2)%2) {
            cout<<-1<<"\n";
            continue;
        }
        dist=(dist1+dist2)/2;
        dist1>dist2?idx=n1:idx=n2;
        cout<<solve(0,SIZE)<<"\n";
    }
}