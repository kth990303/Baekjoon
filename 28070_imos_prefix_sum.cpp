// 230707 #28070 유나의편지쓰기 Gold V
// prefix_sum + imos
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e6+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t,N,p[MAX],pp[MAX],ans=-INF;
string res;
int makestoi(string s) {
    string tmp;
    for (char i : s) {
        if(i=='-')continue;
        tmp+=i;
    }
    return stoi(tmp);
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++) {
        string s1,s2;
        cin>>s1>>s2;
        pp[makestoi(s1)]++;
        pp[makestoi(s2)+1]--;
    }
    for (int i = 200000; i < MAX; i++) {
        p[i]=p[i-1]+pp[i];
        if(ans<p[i]){
            ans=p[i];
            res=to_string(i);
        }
    }
    cout<<res.substr(0,4)<<"-"<<res.substr(4);
}