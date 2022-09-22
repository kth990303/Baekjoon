// 220922 #13911 집구하기 Gold II
// if many starts, insert into priority_queue
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1e4+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,X,Y,d[MAX],dist[MAX];
vector<pi> v[MAX];
vector<int> mac,star;
set<int> res[3];
bool flag[MAX];
priority_queue<pi, vector<pi>, greater<pi>> pq;
void dijkstra(int k){
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d[cur] < cost)
            continue;
        if(!flag[cur])res[k].insert(cur);
        for (auto i : v[cur]) {
            int next = i.second;
            int nCost = i.first + cost;
            if(res[k].count(next))continue;
            if((k==1&&nCost>X) || (k==2&&nCost>Y))continue;
            if (nCost < d[next]) {
                d[next] = nCost;
                pq.push({ nCost, next });
            }
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < M; i++) {
        int n1,n2,cost;
        cin>>n1>>n2>>cost;
        v[n1].push_back({cost,n2});
        v[n2].push_back({cost,n1});
    }
    int cnt;
    cin>>cnt>>X;
    mac.resize(cnt);
    for (int i = 0; i < cnt; i++) {
        cin>>mac[i];
        flag[mac[i]]=true;
    }
    cin>>cnt>>Y;
    star.resize(cnt);
    for (int i = 0;i < cnt; i++) {
        cin>>star[i];
        flag[star[i]]=true;
    }
    fill(d, d + MAX, INF);
    for (int i = 0; i < sz(mac); i++) {
        pq.push({0,mac[i]});
        d[mac[i]]=0;
    }
    dijkstra(1);
    for (auto it=res[1].begin();it!=res[1].end();it++) {
        dist[*it]+=d[*it];
    }
    fill(d, d + MAX, INF);
    for (int i = 0; i < sz(star); i++) {
        pq.push({0,star[i]});
        d[star[i]]=0;
    }
    dijkstra(2);
    int ans=INF;
    for (int i = 1; i <= N; i++) {
        if(flag[i])continue;
        if(!res[1].count(i)||!res[2].count(i))continue;
        ans=min(ans,dist[i]+d[i]);
    }
    cout<<(ans>=INF?-1:ans)<<"\n";
}