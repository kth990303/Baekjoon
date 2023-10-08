// 231008 #1313 합성소수 Gold IV
// dfs + sieve + brute_force
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e7+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t,N;
bool isPrime[MAX],res[MAX];
void sieve() {
    fill(isPrime, isPrime + MAX, true);
    for (int i = 2; i * i < MAX; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i * 2; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
}
void solve(int cur) {
    if(cur>=MAX || !isPrime[cur])return;
    for (int i = 0; i <= 9; ++i) {
        bool flag=true;
        int n=cur*10+i;
        for (int j = 100; j < n; j*=10) {
            if(!isPrime[n%j]){
                flag=false;
                break;
            }
        }
        if(flag){
            res[n]=true;
            solve(n);
        }
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    sieve();
    for (int i = 10; i <= 99; ++i) {
        solve(i);
    }
    vector<int> ans;
    for (int i = 110; i < MAX; ++i) {
        if(res[i] && !isPrime[i])ans.push_back(i);
    }
    cin>>t;
    while(t--){
        cin>>N;
        if(N<=110){
            cout<<-1<<"\n";
            continue;
        }
        int idx= upper_bound(all(ans), N) - ans.begin() - 1;
        cout<<ans[idx]<<"\n";
    }
}
