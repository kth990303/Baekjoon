// 220614 #17613 점프 Platinum II
// math, bitmask, divide_conquer
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 603;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t;
map<pi,int> m;
int calc(int x, int y){
    if(!x && !y)return 0;
    if(m[{x,y}])return m[{x,y}];
    int ret=0;
    int lo=max(1,(int)log2(x-1));
    int hi=log2(y)+1;
    for(int i=lo;i<=hi;i++){
        int s=max(x,(1<<i)-1);
        int e=min(y,(1<<(i+1))-2);
        if(s>e)continue;
        int ss=s-(1<<i)+1;
        int ee=e-(1<<i)+1;
        ret=max(ret, calc(ss,ee)+i);
    }
    return m[{x,y}]=ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<calc(x,y)<<"\n";
    }
}