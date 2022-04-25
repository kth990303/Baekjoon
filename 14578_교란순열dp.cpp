// 220426 #14578 영훈이의 색칠공부 Gold II
// 교란순열 dp
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
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N,d[MAX]={0,0,1,2,9,},fac[MAX]={1,1,2,6,24,};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=5;i<=N;i++){
        d[i]=(d[i-1]+d[i-2])*(i-1);
        fac[i]=fac[i-1]*i;
        d[i]%=MOD;
        fac[i]%=MOD;
    }
    cout<<d[N]*fac[N]%MOD;
}