// 220928 #4160 이혼 Platinum V
// meet in the middle
// 테스트 케이스가 여러 개 주어지는데 하나만 입력받아서 3시간동안 삽질한 문제...
// 문제를 잘읽자
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 24+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX];
map<int,int> m1,m2;
void solve(int st, int cur, int jack, int jil){
    if(!st&&cur>=N/2){
        m1[jack-jil]=max(m1[jack-jil],jack+jil);
        return;
    }
    else if(st&&cur>=N){
        m2[jil-jack]=max(m2[jil-jack],jack+jil);
        return;
    }
    solve(st,cur+1,jack+a[cur],jil);
    solve(st,cur+1,jack,jil+a[cur]);
    solve(st,cur+1,jack,jil);
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        cin>>N;
        if(!N)break;
        int n=0;
        m1.clear();
        m2.clear();
        for (int i = 0; i < N; i++) {
            cin>>a[i];
            n+=a[i];
        }
        int ans=n;
        solve(0,0,0,0);
        solve(N/2,N/2,0,0);
        for(auto it=m2.begin();it!=m2.end();it++){
            if(m1.count(it->first)){
                ans=min(ans,n-(m1[it->first]+it->second));
            }
        }
        cout<<ans<<"\n";
    }
}