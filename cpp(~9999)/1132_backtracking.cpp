// 220622 #1132 합 Gold III
// brute-force, backtracking
// if zero -> brute force
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 53;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,ans;
string s[MAX];
map<char,ll> m;
bool vis[13],nonzero[13];
void solve(int cur, ll num){
    if(cur==m.size()){
        ans=max(ans,num);
        return;
    }
    for(int i=0;i<=9;i++){
        if(!i && nonzero[cur])continue;
        if(!vis[i]){
            vis[i]=true;
            solve(cur+1,num+m[cur+'A']*i);
            vis[i]=false;
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>s[i];
        int len=s[i].length();
        nonzero[s[i][0]-'A']=true;
        for (int j = 0; j < len; j++) {
            m[s[i][j]]+=pow(10,len-j-1);
        }
    }
    solve(0,0);
    cout<<ans;
}