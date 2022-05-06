// 220506 #2479 경로찾기 Gold III
// why G3? Bfs reverse traversal
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e3+7;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,K,S,E,vis[MAX];
vector<string> path;
vector<pi> v[MAX];
vector<int> ans;
void solve(int cur){
    ans.push_back(cur);
    if(cur==S){
        reverse(all(ans));
        for(int i:ans){
            cout<<i+1<<" ";
        }
        exit(0);
    }
    for(auto i:v[cur]){
        if(i.first==1&&vis[i.second]==vis[cur]-1){
            solve(i.second);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;
    path.resize(N);
    for(int i=0;i<N;i++){
        cin>>path[i];
    }
    cin>>S>>E;
    --S;--E;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int cnt=0;
            for(int k=0;k<K;k++){
                if(path[i][k]!=path[j][k]){
                    cnt++;
                }
            }
            v[i].emplace_back(cnt,j);
            v[j].emplace_back(cnt,i);
        }
    }
    fill(vis,vis+MAX,-1);
    queue<pi> q;
    q.push({0,S});
    vis[S]=0;
    while(!q.empty()){
        int t=q.front().first;
        int cur=q.front().second;
        q.pop();
        if(cur==E)solve(cur);
        for(auto i:v[cur]){
            if(vis[i.second]==-1&&i.first==1){
                vis[i.second]=t+1;
                q.push({t+1,i.second});
            }
        }
    }
    cout<<-1;
}