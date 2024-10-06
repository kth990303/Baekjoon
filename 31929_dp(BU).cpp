// 241006 #31929 너 재능있어 G4
// dp (BU)
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
int N,M,a[MAX],b[MAX],K,ans,d[MAX][MAX];
int dp(int n1,int n2){
    if(n1>=N||n2>=M)return 0;
    int& ret=d[n1][n2];
    if(~ret)return ret;
    ret=0;
    int k1=dp(n1+1,n2)+a[n1];
    int k2=dp(n1,n2+1);
    if(k2%K)k2-=k2%K;
    else k2-=b[n2];
    if(n1<N-1&&n2<M-1)ret=max(k1,k2);
    else if(n1<N-1)ret=k1;
    else if(n2<M-1)ret=k2;
    else ret=0;
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    cin>>M;
    for (int i = 0; i < M; ++i) {
        cin>>b[i];
    }
    cin>>K;
    memset(d,-INF,sizeof(d));
    d[0][0]=0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            int k1=d[i][j]+a[i];
            int k2=d[i][j]-b[j];
            if(d[i][j]%K)k2=max(k2,(d[i][j]<0 ? d[i][j]/K-1: d[i][j]/K)*K);
            d[i+1][j]=max(d[i+1][j],k1);
            d[i][j+1]=max(d[i][j+1],k2);
        }
    }
    cout<<d[N][M];
}
