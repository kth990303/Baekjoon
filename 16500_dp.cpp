// 221104 #16500 문자열판별 Gold V
// dp + impl + string
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e2+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
string s;
int N,d[MAX];
vector<int> v[MAX];
int dp(int cur){
    if(cur>=sz(s))return cur==sz(s)?1:0;
    int& ret=d[cur];
    if(~ret)return ret;
    ret=0;
    for(auto i:v[cur]){
        ret=max(ret,dp(i));
    }
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>s>>N;
    for (int i = 0; i < N; i++) {
        string k;cin>>k;
        for (int j = 0; j+sz(k)<=sz(s); j++) {
            if(s.substr(j,sz(k))==k){
                v[j].push_back(j+sz(k));
            }
        }
    }
    memset(d,-1,sizeof(d));
    cout<<dp(0);
}