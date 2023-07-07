// 230707 #28283 해킹 Gold IV
// bfs + greedy
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 5e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,X,Y,a[MAX],b[MAX],res[MAX];
vector<int> v[MAX];
int vis[MAX];
queue<pi> q;
bool cmp(int n1, int n2){
    return n1>n2;
}
void bfs(){
    while(!q.empty()) {
        int time=q.front().first;
        int cur=q.front().second;
        q.pop();
        for(auto i:v[cur]){
            if(vis[i]!=-1)continue;
            vis[i]=time+1;
            q.push({time+1, i});
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>X>>Y;
    for (int i = 1; i <= N; i++) {
        cin>>a[i];
    }
    for (int i = 0; i < M; i++) {
        int n1,n2;cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    fill(vis,vis+N+1,-1);
    for (int i = 0; i < Y; i++) {
        cin>>b[i];
        q.push({0,b[i]});
        vis[b[i]]=0;
    }
    bfs();
    for (int i = 1; i <= N; i++) {
        res[i]=vis[i]*a[i];
        if(res[i]<0){
            cout<<-1;
            return 0;
        }
    }
    sort(res+1,res+N+1,cmp);
    int ans=0;
    for (int i = 1; i <= X; i++) {
        ans+=res[i];
    }
    cout<<ans;
}