// 220930 #20444 색종이와 가위 Gold V
// math
// another solution: binary_search (a+b, ab) -> a=0, b=N/2 -> parametric_search
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
int N,K;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;
    int mul=K-N-1;
    int diff2=N*N-4*mul;
    if(mul<0 || diff2<0){
        cout<<"NO";
        return 0;
    }
    int diff= sqrt(diff2);
    if(diff*diff!=diff2){
        cout<<"NO";
        return 0;
    }
    if((N+diff)%2){
        cout<<"NO";
        return 0;
    }
    int a=(N+diff)/2;
    int b=N-a;
    if(a<0||b<0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}