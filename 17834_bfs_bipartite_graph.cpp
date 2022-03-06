// 220306 #17834 사자와토끼 Platinum V
// bipartite graph를 구현할 수 있는지 묻는 문제
// Platinum급은 아닌 거 같다고 생각...
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 50011;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,d[MAX];
ll ans[2];
vector<int> v[MAX];
void bfs(){
    queue<pi> q;
    q.push({0, 1});
    d[1]=0;
    while(!q.empty()){
        int cur=q.front().second;
        int dis=q.front().first;
        q.pop();
        ans[dis%2]++;
        for(int i:v[cur]){
            if(d[i]==-1){
                d[i]=dis+1;
                q.push({dis+1,i});
            }
            else if(d[i]%2==dis%2){
                ans[0]=0;
                ans[1]=0;
                return;
            }
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    fill(d,d+MAX,-1);
    bfs();
    cout<<2*ans[0]*ans[1];
}