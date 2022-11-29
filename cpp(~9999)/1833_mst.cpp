// 221129 #1833 고속철도 설계하기 Gold III
// mst basic
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,p[MAX],C,M;
vector<pii> v;
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
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N; i++) {
        p[i]=i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cost;cin>>cost;
            if(cost<0){
                C-=cost;
                merge(i,j);
            }
            else if(cost>0)v.push_back({abs(cost),{i,j}});
        }
    }
    C/=2;
    sort(all(v));
    vector<pi> ans;
    for (int i = 0; i < sz(v); i++) {
        int n1=v[i].second.first;
        int n2=v[i].second.second;
        int cost=v[i].first;
        if(find(n1)!=find(n2)){
            M++;
            C+=cost;
            merge(n1,n2);
            ans.push_back({n1,n2});
        }
    }
    cout<<C<<" "<<M<<"\n";
    for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n";
}