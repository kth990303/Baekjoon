// 27468 2배 또는 0.5배 Gold V
// adhoc
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e6+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,k1[4]={1,3,2,4},k2[4]={1,2,4,3};
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    cout<<"YES\n";
    if(N%4==2){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 4; ++j) {
                int n=i*4+k2[j];
                if(n>N)exit(0);
                cout<<n<<" ";
            }
        }
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            int n=i*4+k1[j];
            if(n>N)exit(0);
            cout<<n<<" ";
        }
    }
}
