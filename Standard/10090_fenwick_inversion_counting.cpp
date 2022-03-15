// 220315 #10090 Counting Inversion Platinum V
// fenwick tree version
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+3;
int N,a[MAX],tree[MAX];
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
    ll ans=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        ans+=query(N)-query(a[i]);
        update(a[i],1);
    }
    cout<<ans;
}