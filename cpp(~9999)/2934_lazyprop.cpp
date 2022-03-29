// 220329 #2934 LRH 식물 Platinum IV
// lazyprop
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e5+3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
struct Tree {
    int val, lazy;
};
int N,a[MAX];
Tree tree[1<<18];
void update_lazy(int node, int s, int e) {
    if (tree[node].lazy) {
        tree[node].val += (e - s + 1) * tree[node].lazy;
        if (s != e) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}
int query(int node, int s, int e, int left, int right) {
    update_lazy(node, s, e);
    if (e < left || right < s)
        return 0;
    if (left <= s && e <= right)
        return tree[node].val;
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, left, right)
           + query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int left, int right, int diff) {
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
    cin>>N;
    for(int i=0;i<N;i++){
        int l,r;
        cin>>l>>r;
        int n1=query(1,1,MAX-2,l,l);
        int n2=query(1,1,MAX-2,r,r);
        cout<<n1+n2<<"\n";
        update(1,1,MAX-2,l,l,-n1);
        update(1,1,MAX-2,r,r,-n2);
        update(1,1,MAX-2,l+1,r-1,1);
    }
}