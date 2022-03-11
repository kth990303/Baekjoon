// 220311 #15816 퀘스트중인모험가 Platinum IV
// segtree + coordination_compress
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 2e6+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,Q,a[MAX],tree[MAX];
vector<int> v;
vector<pi> q;
int query(int i){
    int ret=0;
    for(;i;i-=i&-i){
        ret+=tree[i];
    }
    return ret;
}
void update(int i,int val){
    for(;i<=N;i+=i&-i){
        tree[i]+=val;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    cin>>Q;
    int initN=N;
    while(Q--){
        int ch,L,R;
        cin>>ch>>L;
        if(ch==1){
            v.push_back(L);
            q.push_back({L,INF});
            ++N;
        }
        else{
            cin>>R;
            q.push_back({L,R});
        }
    }
    sort(all(v));
    for(int i=0;i<initN;i++){
        int n=lower_bound(all(v), a[i])-v.begin()+1;
        update(n,1);
    }
    for(pi i:q){
        if(i.second==INF){
            int n=lower_bound(all(v), i.first)-v.begin()+1;
            update(n,1);
        }
        else{
            int cnt=i.second-i.first+1;
            int left=lower_bound(all(v),i.first)-v.begin()+1;
            int right=upper_bound(all(v),i.second)-v.begin()+1;
            cout<<cnt-(query(right-1)-query(left-1))<<"\n";
        }
    }
}