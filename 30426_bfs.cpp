// 240107 #30426 Rebirth Gold IV
// BFS, DP
// i번째 문제를 풀었을 때, K 차원으로 이동되는 여러 경우의수가 존재하므로 방문처리해주어야 됨.
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 3e3+7;
const int MAX_K = 1e7+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,K,g[MAX],y[MAX],L,x[MAX];
bool vis[MAX][MAX];
bool bfs() {
    queue<pi> q;
    q.push({0,M});
    vis[0][M]=true;
    while(!q.empty()) {
        int cur=q.front().first;
        int idx=q.front().second;
        q.pop();
        if(cur>K)continue;
        int nxt1=(idx+g[cur])%N;
        int nxt2=(idx+y[cur])%N;
        if(cur==K && !idx)return true;
        if(!vis[cur+1][nxt1] && !x[nxt1]) {
            vis[cur+1][nxt1]=true;
            q.push({cur + 1, nxt1});
        }
        if(!vis[cur+1][nxt2] && !x[nxt2]){
            vis[cur+1][nxt2]=true;
            q.push({cur+1,nxt2});
        }
    }
    return false;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for (int i = 0; i < K; ++i) {
        cin>>g[i]>>y[i];
    }
    cin>>L;
    for (int i = 0; i < L; ++i) {
        int n;cin>>n;
        x[n]=1;
    }
    if(bfs())cout<<"utopia";
    else cout<<"dystopia";
}
