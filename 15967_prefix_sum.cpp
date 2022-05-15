// 220515 #15976 XCorr Gold III
// binary_search, prefix_sum
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 3e5+7;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,M,A,B,p[MAX],ans;
vector<ll> x,y,X,Y;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    X.push_back(0);
    for(int i=0;i<N;i++){
        ll idx,val;
        cin>>idx>>val;
        x.push_back(idx);
        X.push_back(val);
    }
    cin>>M;
    Y.push_back(0);
    for(int i=0;i<M;i++){
        ll idx,val;
        cin>>idx>>val;
        y.push_back(idx);
        Y.push_back(val);
    }
    for(int i=1;i<=M;i++){
        p[i]=p[i-1]+Y[i];
    }
    cin>>A>>B;
    for(int i=0;i<N;i++){
        ll s=lower_bound(all(y), x[i]+A)-y.begin();
        ll e=upper_bound(all(y), x[i]+B)-y.begin();
        ans+=X[i+1]*(p[e]-p[s]);
    }
    cout<<ans;
}