// 220506 #18937 왕들의 외나무다리 돌게임 Platinum III
// sprague-grundy : nim_game
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e5+7;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX],ans;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        ans^=(a[i]-2);
    }
    string s;
    cin>>s;
    if(ans)cout<<s;
    else cout<<(s=="Whiteking"?"Blackking":"Whiteking");
}