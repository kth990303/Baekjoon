// 221208 #17209 새내기와헌내기 Gold II
// dsu, 이분그래프
// 근데 왜 알고리즘 분류에 dsu(분리집합)은 없음..?
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 2e3+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N,p[MAX*2],ans;
map<int, int> m;
bool vis[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
    if (a > b)swap(a,b);
	p[b] = a;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N*2; i++) {
        p[i]=i;
    }
    vector<pi> v;
    for (int i = 0; i < N; i++) {
        string s;
        cin>>s;
        for (int j = 0; j < N; j++) {
            if(s[j]=='1')v.push_back({i+1,j+1});
        }
    }
    for (int i = 0; i < sz(v); i++) {
        int n1=v[i].first;
        int n2=v[i].second;
        merge(n1, n2+N);
        merge(n2,n1+N);
    }
    for (int i = 1; i <= N; i++) {
        m[find(i)]++;
    }
    for (int i = 1; i <= N; i++) {
        int n=find(i);
        int r=find(i+N);
        if(n==i && r==n+N){
            ans++;
            continue;
        }
        if(n==i && !vis[r]){
            ans+=max(m[n],m[r]);
            vis[n]=true;
            vis[r]=true;
        }
    }
    cout<<ans;
}