// 220416 #16889 중복없는님게임 Platinum I
// dfs -> runtime 전처리
// tree height grundy number
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 63;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,n,ans,d[MAX]={0,1,1,};
void solve(){
    int cnt=3;
    for(int i=3,j=2,k=0;i<MAX;i++,k++){
        if(k==cnt){
            k=0;
            cnt++;
            ++j;
        }
        d[i]=j;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>n;
        ans^=d[n];
    }
    cout<<(ans?"koosaga":"cubelover");
}