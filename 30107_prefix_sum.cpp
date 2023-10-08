// 231008 #30107 popcount Platinum V
// bitmask + prefix_sum
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 5e6+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t,N,A,B,d[MAX],pa[MAX],pb[MAX];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 500000; ++i) {
        d[i]=bitset<20>(i).count();
    }
    vector<pi> v;
    for (int i = 1; i <= 500000; ++i) {
        int a=pow(2,(int)log2(i+1))-1;
        int b=i-a;
        pa[i]=pa[i-1]+max(d[a],d[b]);
        pb[i]=pb[i-1]+min(d[a],d[b]);
    }
    cin>>t;
    while(t--){
        cin>>N>>A>>B;
        int ans=0;
        if(A<B)swap(A,B);
        ans=A*pa[N]+B*pb[N];
        cout<<ans<<"\n";
    }
}
