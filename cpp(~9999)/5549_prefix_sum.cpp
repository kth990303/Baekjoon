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
int N,M,K,sx,sy,ex,ey,J[MAX][MAX],I[MAX][MAX],O[MAX][MAX];
char a[MAX][MAX];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin>>a[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            J[i][j]+=J[i-1][j]+J[i][j-1]-J[i-1][j-1]+(a[i][j]=='J');
            I[i][j]+=I[i-1][j]+I[i][j-1]-I[i-1][j-1]+(a[i][j]=='I');
            O[i][j]+=O[i-1][j]+O[i][j-1]-O[i-1][j-1]+(a[i][j]=='O');
        }
    }
    while(K--){
        cin>>sy>>sx>>ey>>ex;
        cout<<J[ey][ex]-J[ey][sx-1]-J[sy-1][ex]+J[sy-1][sx-1]<<" ";
        cout<<O[ey][ex]-O[ey][sx-1]-O[sy-1][ex]+O[sy-1][sx-1]<<" ";
        cout<<I[ey][ex]-I[ey][sx-1]-I[sy-1][ex]+I[sy-1][sx-1]<<"\n";
    }
}