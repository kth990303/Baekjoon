// 220320 #2517 달리기 Platinum IV
// fenwick tree inversion counting solution
// O(NlgN)
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 5e5+3;
const int SIZE = 16;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX],tree[MAX],ans[MAX];
vector<pi> v;
ll query(int i){
    ll ret=0;
    for(;i;i-=i&-i){
        ret+=1LL*tree[i];
    }
    return ret;
}
void update(int i, int val){
    for(;i<=N;i+=i&-i){
        tree[i]+=val;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        int n; cin>>n;
        v.push_back({n,i});
    }
    sort(all(v));
    for(int i=0;i<sz(v);i++){
        ans[v[i].second]=v[i].second-query(v[i].second);
        update(v[i].second,1);
    }
    for(int i=1;i<=N;i++){
        cout<<ans[i]<<"\n";
    }
}