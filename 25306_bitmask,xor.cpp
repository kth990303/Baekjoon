// 220710 #25306 연속 XOR Gold IV
// bitmask, xor
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e3+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int A,B;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>A>>B;
    int a=A/4+1,b=B/4,ans=A;
    for (int i = A+1; i < 4*a; i++) {
        ans^=i;
    }
    for (int i = b*4; i <= B; i++) {
        ans^=i;
    }
    cout<<ans;
}