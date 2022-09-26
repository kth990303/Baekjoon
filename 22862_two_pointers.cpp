// 220926 #22862 가장 긴 짝 연속한 부분수열 Gold V
// small, large all common solution
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e6+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,K;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin>>v[i];
    }
    int s=0,ans=v[0]%2==0,cnt=v[0]%2;
    for (int i = 1; i < N; i++) {
        if(v[i]%2)cnt++;
        if(cnt<=K){
            ans=max(ans,i-s-cnt+1);
        }
        else{
            if(v[s++]%2)cnt--;
        }
    }
    cout<<ans;
}