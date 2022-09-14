// 220915 #1414 불우이웃돕기 Gold III
// gold random set - basic mst...
// O(N^2log(N^2))
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 50+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,p[MAX];
vector<pii> v;
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
    if (a > b)
        swap(a,b);
	p[b] = a;
	return true;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    int ans=0;
    for (int i = 1; i <= N; i++) {
        p[i]=i;
    }
    for (int i = 1; i <= N; i++) {
        string s;
        cin>>s;
        for (int j = 1; j <= N; j++) {
            if(s[j-1]=='0')continue;
            if(s[j-1]>='a'&&s[j-1]<='z') {
                ans+=s[j-1]-'a'+1;
                v.push_back({s[j-1] - 'a' + 1, {i, j}});
            }
            else if(s[j-1]>='A'&&s[j-1]<='Z'){
                ans+=s[j-1]-'A'+27;
                v.push_back({s[j-1]-'A'+27, {i,j}});
            }
        }
    }
    sort(all(v));
    for (int i = 0; i < sz(v); i++) {
        int n1=v[i].second.first;
        int n2=v[i].second.second;
        int cost=v[i].first;
        if(find(n1)!=find(n2)){
            merge(n1,n2);
            ans-=cost;
        }
    }
    for (int i = 2; i <= N; i++) {
        if(find(1)!=find(i)){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
}