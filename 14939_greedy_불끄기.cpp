// 221206 #14939 불끄기 Platinum V
// greedy, brute-force
// 이제는 웰노운이 되어버린 문제...
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 10+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int ans=INF;
void solve(int cur, vector<int> flag, int cnt){
    if(cur==10){
        if(!flag[9])ans=min(ans,cnt);
        return;
    }
    int nCnt=cnt;
    for (int i = 0; i < 10; i++) {
        if(flag[cur-1]&(1<<i)){
            nCnt++;
            flag[cur]^=(1<<i);
            if(i-1>=0)flag[cur]^=(1<<(i-1));
            if(i+1<10)flag[cur]^=(1<<(i+1));
            if(cur+1<10)flag[cur+1]^=(1<<i);
        }
    }
    solve(cur+1,flag,nCnt);
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        int now=0;
        string s;
        cin>>s;
        for (int j = 0; j < 10; j++) {
            if(s[j]=='O')now|=(1<<j);
        }
        v.push_back(now);
    }
    for (int i = 0; i < (1 << 10); i++) {
        vector<int> tmp=v;
        int k=0;
        for (int j = 0; j < 10; j++) {
            if(i&(1<<j)){
                tmp[0]^=(1<<j);
                if(j+1<10)tmp[0]^=(1<<(j+1));
                if(j-1>=0)tmp[0]^=(1<<(j-1));
                tmp[1]^=(1<<j);
                k++;
            }
        }
        solve(1,tmp,k);
    }
    cout<<(ans==INF?-1:ans);
}