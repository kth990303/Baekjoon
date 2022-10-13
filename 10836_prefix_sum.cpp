// 221013 #10836 여왕벌 Gold IV
// prefix_sum, impl
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 7e2+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,a[MAX][MAX],cnt[3],pp[1407],p[1407];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>M>>N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            a[i][j]=1;
        }
    }
    for (int i = 0; i < N; i++) {
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        pp[n0+1]+=1;
        pp[n0+n1+1]++;
    }
    for (int i = 1; i <= 2*M-1; i++) {
        p[i]=p[i-1]+pp[i];
    }
    for (int i = 1; i <= 2 * M - 1; i++) {
        int y=max(1LL, M-i+1), x=max(1LL,i-M+1);
        a[y][x]+=p[i];
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            if(i==1||j==1)continue;
            a[i][j]=max({a[i][j],a[i-1][j-1],a[i-1][j],a[i][j-1],a[i-1][j]});
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}