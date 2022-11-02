// 221102 #1863 스카이라인 쉬운거 Gold IV
// use stack
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 5e4+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX],ans;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++) {
        int x,y;cin>>x>>y;
        a[i]=y;
    }
    vector<int> v;
    for (int i = N-1; i >= 0; i--) {
        while(!v.empty()) {
            if(v.back()>a[i]){
                v.pop_back();
            } else break;
        }
        if(!a[i] || (!v.empty()&&v.back()==a[i]))continue;
        ans++;
        v.push_back(a[i]);
    }
    cout<<ans;
}