// 221220 #11985 오렌지 출하 Gold V
// top-down으로 풀려다가 안풀려서 bottom-up으로 함
// O(NM)
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e4+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,K,a[MAX],d[MAX];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for (int i = 0; i < N; i++) {
        cin>>a[i];
        d[i]=INF;
    }
    d[0]=K;
    for (int i = 1; i < N; i++) {
        int lo=INF,hi=0;
        for (int j = i; j >= max(0LL,i-M+1); j--) {
            lo=min(lo,a[j]),hi=max(hi,a[j]);
            d[i]=min(d[i],d[j-1]+(hi-lo)*(i-j+1)+K);
        }
    }
    cout<<d[N-1];
}