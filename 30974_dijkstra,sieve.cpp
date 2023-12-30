// 231230 #30974 WWhat's your ETA? Gold IV
// dijkstra, sieve
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 4e5+7;
const int MAX_K = 1e7+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,a[MAX],d[MAX];
vector<pi> v[MAX];
bool isPrime[10000007];
void sieve() {
    fill(isPrime, isPrime + MAX_K, true);
    for (int i = 2; i * i < MAX_K; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i * 2; j < MAX_K; j += i) {
            isPrime[j] = false;
        }
    }
}
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
            int next=i.second;
            int nCost=i.first+cost;
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
    sieve();
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < M; ++i) {
        int n1,n2,cost;
        cin>>n1>>n2>>cost;
        if(isPrime[a[n1]+a[n2]]) {
            v[n1].push_back({cost,n2});
            v[n2].push_back({cost,n1});
        }
    }
    dijkstra(1);
    if(d[N]>=INF)cout<<"Now where are you?";
    else cout<<d[N];
}
