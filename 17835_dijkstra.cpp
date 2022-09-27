// 220927 #17835 면접보는 승범이네 Gold II
// dijkstra many end(start)_point
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
int N,M,K,d[MAX],ans;
vector<pi> v[MAX];
vector<int> place;
priority_queue<pi, vector<pi>, greater<pi>> pq;
void dijkstra(){
    fill(d, d + MAX, INF);
    for (int i = 0; i < K; i++) {
        d[place[i]]=0;
    }
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d[cur] < cost)
            continue;
        for (auto i : v[cur]) {
            int next = i.second;
            int nCost = i.first + cost;
            if (nCost < d[next]) {
                d[next] = nCost;
                pq.push({ nCost, next });
            }
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for (int i = 0; i < M; i++) {
        int n1,n2,cost;
        cin>>n1>>n2>>cost;
        v[n2].push_back({cost,n1});
    }
    place.resize(K);
    for (int i = 0; i < K; i++) {
        cin>>place[i];
        pq.push({0,place[i]});
    }
    dijkstra();
    int ans=0,idx=0;
    for (int i = 1; i <= N; i++) {
        if(ans<d[i]){
            ans=d[i];
            idx=i;
        }
    }
    cout<<idx<<"\n"<<ans;
}