// 220919 #16472 고냥이 Gold IV
// two_pointers
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e3+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,vis[30];
string str;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>str;
    int M=sz(str);
    int s=0,e=0,cnt,ans=0;
    map<char,int> m;
    m[str[0]]++;
    while(s!=M){
        ans=max(ans,e-s+1);
        if(e<M-1){
            if(sz(m)<N) {
                m[str[++e]]++;
                continue;
            }
            if(sz(m)==N&&m[str[e+1]]){
                m[str[++e]]++;
                continue;
            }
        }
        if(m[str[e+1]]==0)m.erase(str[e+1]);
        if(--m[str[s]]==0)m.erase(str[s]);
        s++;
    }
    cout<<ans;
}