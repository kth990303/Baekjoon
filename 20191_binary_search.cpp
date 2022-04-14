// 220415 #20191 줄임말 Gold II
// binary_search, sliding_window
// 다른 분들은 웰노운이라던데 왜 나는 언노운일까
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e6+3;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
string s,t;
vector<int> v[150];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>s>>t;
    for(int i=0;i<t.size();i++){
        v[t[i]].push_back(i);
    }
    for(auto i:s){
        if(v[i].empty()){
            cout<<-1;
            return 0;
        }
    }
    int idx=-1, ans=1;
    for(auto i:s){
        auto it = upper_bound(all(v[i]), idx);
        if(it==v[i].end()){
            ans++;
            idx=-1;
            it = upper_bound(all(v[i]), idx);
        }
        idx=*it;
    }
    cout<<ans;
}