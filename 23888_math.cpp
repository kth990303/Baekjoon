// 220526 #23888 등차수열과 쿼리 Silver I
// number_theory, math
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll A,D,Q;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>A>>D>>Q;
    while(Q--){
        int ch;
        ll l,r;
        cin>>ch>>l>>r;
        if(ch==1){
            l--; r--;
            cout<<(r-l+1)*A+(r*(r+1)/2-l*(l-1)/2)*D<<"\n";
        }
        else{
            if(l==r)cout<<A+(l-1)*D<<"\n";
            else cout<<gcd(A,D)<<"\n";
        }
    }
}