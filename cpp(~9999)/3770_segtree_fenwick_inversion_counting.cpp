// 220929 #3770 대한민국 Platinum V
// segtree, fenwick tree_ inversion_counting
// O(KlogM * test_case)
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e3+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,K,tree[MAX];
vector<int> v[MAX];
int query(int i){
    int ret=0;
    for(;i;i-=i&-i){
        ret+=tree[i];
    }
    return ret;
}
void update(int i,int val){
    for(;i<=M;i+=i&-i){
        tree[i]+=val;
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    for (int t = 1; t <= T; t++) {
        cin>>N>>M>>K;
        fill(tree+1,tree+M+1,0);
        for (int i = 1; i <= max(N,M); i++) {
            v[i].clear();
        }
        int ans=0;
        for (int i = 0; i < K; i++) {
            int n1,n2;
            cin>>n1>>n2;
            v[n1].push_back(n2);
        }
        for (int i = 1; i <= N; i++) {
            for(auto j:v[i]){
                ans+=query(M)-query(j);
            }
            for(auto j:v[i]){
                update(j,1LL);
            }
        }
        cout<<"Test case "<<t<<": "<<ans<<"\n";
    }
}