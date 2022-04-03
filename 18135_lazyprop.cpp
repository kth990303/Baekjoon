// 220403 #18135 겨울나기 Platinum IV
// lazyprop Standard
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
struct Tree {
    ll val, lazy;
};
ll N,M;
Tree tree[1<<21];
void update_lazy(int node, int s, int e) {
    if (tree[node].lazy) {
        tree[node].val += (1LL*e - s + 1) * tree[node].lazy;
        if (s != e) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}
ll query(int node, int s, int e, int left, int right) {
    update_lazy(node, s, e);
    if (e < left || right < s)
        return 0;
    if (left <= s && e <= right)
        return tree[node].val;
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, left, right)
           + query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int left, int right, ll diff) {
    update_lazy(node, s, e);
    if (e < left || right < s)
        return;
    if (left <= s && e <= right) {
        tree[node].lazy += diff;
        update_lazy(node, s, e);
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, left, right, diff);
    update(node * 2 + 1, mid + 1, e, left, right, diff);
    tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    vector<ll> idx;
    for(int i=1;i<=M;i++){
        ll n1,n2,k;
        cin>>n1>>n2>>k;
        idx.push_back(n1);
        update(1,1,M,i,i,k);
    }
    ll ch,x,y,z;
    while(cin>>ch>>x>>y&&ch){
        if(x>y){
            x=upper_bound(all(idx), x)-idx.begin();
            y=upper_bound(all(idx), y)-idx.begin();
            if(x==y)y--;
            if(ch==1){
                cout<<query(1,1,M,x,M)+query(1,1,M,1,y)<<"\n";
            }
            else{
                cin>>z;
                update(1,1,M,x,M,z);
                update(1,1,M,1,y,z);
            }
        }
        else{
            x=upper_bound(all(idx), x)-idx.begin();
            y=upper_bound(all(idx), y)-idx.begin();
            if(ch==1){
                cout<<query(1,1,M,x,y)<<"\n";
            }
            else{
                cin>>z;
                update(1,1,M,x,y,z);
            }
        }
    }
}