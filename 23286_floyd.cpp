// 230525 #23286 허들 넘기 Gold III
// floyd
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 3e2+2;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,M,K,d[MAX][MAX];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    memset(d,INF,sizeof(d));
    for (int i = 0; i < M; i++) {
        int n1,n2,cost;cin>>n1>>n2>>cost;
        d[n1][n2]=cost;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int n1,n2;cin>>n1>>n2;
        cout<<(d[n1][n2]==INF?-1:d[n1][n2])<<"\n";
    }
}