// 220413 #6054 Relay race Gold V
// simulation, dijkstra
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e3+3;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,t[MAX],d[MAX];
vector<int> v[MAX];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        int cnt;
        cin>>t[i]>>cnt;
        while(cnt--){
            int k;
            cin>>k;
            v[i].push_back(k);
        }
    }
    priority_queue<pi,vector<pi>,greater<>> pq;
    fill(d,d+MAX,INF);
    d[1]=t[1];
    pq.push({t[1],1});
    int cnt=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(++cnt==N){
            cout<<cost;
            return 0;
        }
        if(d[cur]<cost)continue;
        for(int i:v[cur]){
            if(d[i]<INF)continue;
            int nCost=cost+t[i];
            if(nCost<d[i]){
                d[i]=nCost;
                pq.push({nCost,i});
            }
        }
    }
}