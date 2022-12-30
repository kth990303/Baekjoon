// 221230 #14570 나무 위의 구슬 Gold II
// dfs, math, ad_hoc
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
int N,n1,n2,K;
vector<int> v[MAX];
int solve(int cur){
    if(v[cur][0]==-1&&v[cur][1]==-1)return cur; // 자식이 없을 때
    else if(v[cur][0]==-1)return solve(v[cur][1]); // 자식이 1개
    else if(v[cur][1]==-1)return solve(v[cur][0]); // 자식이 1개
    for(auto i:v[cur]){
        if(K%2){
            K/=2;K++; // 서브트리 구슬 개수 합
            return solve(v[cur][0]);
        }
        else {
            K/=2; // 서브트리 구슬 개수 합
            return solve(v[cur][1]);
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N; i++) {
        cin>>n1>>n2;
        v[i].push_back(n1);
        v[i].push_back(n2);
    }
    cin>>K;
    cout<<solve(1);
}