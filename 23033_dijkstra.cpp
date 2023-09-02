// 230902 #23033 집에빨리가고싶어! Gold II
// dijkstra
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
int N,M,d[MAX];
vector<pii> v[MAX];
void dijkstra(int s){
    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0,s});
    fill(d,d+MAX,INF);
    d[s]=0;
    while(!pq.empty()) {
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(d[cur]<cost)continue;
        for(auto i:v[cur]){
            int next=i.second.first;
            int nCost=i.first+cost;
            int nw=i.second.second;
            if(cost%nw)nCost+=nw-(cost%nw);
            if(nCost < d[next]){
                d[next]=nCost;
                pq.push({nCost,next});
            }
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int a,b,t,w;
        cin>>a>>b>>t>>w;
        v[a].push_back({t,{b,w}});
    }
    dijkstra(1);
    cout<<d[N];
}
