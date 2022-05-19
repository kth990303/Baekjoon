// 220519 #24391 귀찮은 해강이 Gold V
// union_find basic
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,p[MAX],k1,k2,ans;
int find(int a){
    if(a==p[a])return a;
    return p[a]=find(p[a]);
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(a>b)swap(a,b);
    p[b]=a;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++)p[i]=i;
    for(int i=0;i<M;i++){
        int n1,n2;
        cin>>n1>>n2;
        merge(n1,n2);
    }
    cin>>k1;
    for(int i=0;i<N-1;i++){
        cin>>k2;
        if(find(k1)!=find(k2))ans++;
        k1=k2;
    }
    cout<<ans;
}