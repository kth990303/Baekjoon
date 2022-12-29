// 221229 #14941 호기심 Gold II
// sieve, prefix_sum, math, binary_search
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,p[2][MAX];
bool isPrime[MAX];
vector<int> v;
void sieve() {
    fill(isPrime, isPrime + MAX, true);
    for (int i = 2; i * i < MAX; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i * 2; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
    v.push_back(2);
    for (int i = 3; i < MAX; i+=2) {
        if(isPrime[i])v.push_back(i);
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    sieve();
    for (int i = 0; i < sz(v); i++) {
        if(!i){
            p[0][0]=3*v[0];
            continue;
        }
        if(i%2==0)p[0][i]=p[0][i-1]+3*v[i];
        else p[0][i]=p[0][i-1]-v[i];
    }
    for (int i = 1; i < sz(v); i++) {
        if(i%2==0)p[1][i]=p[1][i-1]-v[i];
        else p[1][i]=p[1][i-1]+3*v[i];
    }
    while(N--){
        int n1,n2;cin>>n1>>n2;
        int lo= lower_bound(all(v),n1)-v.begin();
        int hi= upper_bound(all(v),n2)-v.begin()-1;
        if(!lo)cout<<p[lo%2][hi]<<"\n";
        else cout<<p[lo%2][hi]-p[lo%2][lo-1]<<"\n";
    }
}