// 230929 #30023 전구상태바꾸기 Gold V
// greedy, impl
// 직전 상태만 고려 + 첫번째 스위치는 0, 1, 2 모두 고려
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
int N,a[3][MAX],res[3];
void ch(int ar,int cur){
    a[ar][cur-1]=(a[ar][cur-1]+1)%3;
    a[ar][cur]=(a[ar][cur]+1)%3;
    a[ar][cur+1]=(a[ar][cur+1]+1)%3;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>N>>s;
    for (int i = 0; i < N; ++i) {
        if(s[i]=='R')a[0][i]=a[1][i]=a[2][i]=0;
        if(s[i]=='G')a[0][i]=a[1][i]=a[2][i]=1;
        if(s[i]=='B')a[0][i]=a[1][i]=a[2][i]=2;
    }
    ch(1,1);res[1]++;
    ch(2,1);res[2]++;
    ch(2,1);res[2]++;
    for (int i = 1; i < N-2; ++i) {
        for (int j = 0; j < 3; ++j) {
            while(a[j][i]!=a[j][0]){
                ch(j,i+1);
                res[j]++;
            }
        }
    }
    int ans=INF;
    for (int i = 0; i < 3; ++i) {
        bool flag=true;
        for (int j = 0; j < N; ++j) {
            if(a[i][j]!=a[i][0]){
                flag=false;
                break;
            }
        }
        if(flag)ans=min(ans,res[i]);
    }
    cout<<(ans==INF?-1:ans);
}
