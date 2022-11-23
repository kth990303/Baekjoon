// 221123 #20542 받아쓰기 Gold III
// dp, string
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
string s,p;
int N,M;
vector<vector<int>> d;
bool check(char s, char p) {
    if(s=='i')return p=='i'||p=='j'||p=='l';
    if(s=='v')return p=='v'||p=='w';
    return s==p;
}
int dp(int cur1, int cur2){
    if(cur1>=N)return M-cur2;
    if(cur2>=M)return N-cur1;
    int& ret=d[cur1][cur2];
    if(~ret)return ret;
    ret=INF;
    if(check(s[cur1],p[cur2]))return ret=dp(cur1+1,cur2+1);
    if(cur1<N)ret=min(ret,dp(cur1+1,cur2)+1);
    if(cur2<M)ret=min(ret,dp(cur1,cur2+1)+1);
    ret=min(ret,dp(cur1+1,cur2+1)+1);
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>s>>p;
    d.resize(N);
    for (int i = 0; i < N; i++) {
        d[i].resize(M);
        for (int j = 0; j < M; j++) {
            d[i][j]=-1;
        }
    }
    cout<<dp(0,0);
}