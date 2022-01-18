// 220118 #2208 보석줍기 Gold II
// prefix_sum
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,a[MAX],p[MAX],p2[MAX],ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        p[i]=p[i-1]+a[i];
        if(i>M)
            p2[i - M] = min(p2[i - M - 1], p[i - M - 1] + a[i - M]);
        if(i>=M)
            ans = max(ans, p[i] - p2[i - M]);
    }
    cout<<ans;
}