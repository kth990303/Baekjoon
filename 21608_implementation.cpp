//220305 #21608 상어초등학교 Silver I
//삼성sw역량 A형
//implementation
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 22;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,a[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
vector<int> v;
set<int> s[MAX*MAX];
int check(int x, int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=N||ny>=N)continue;
        if(!a[ny][nx])cnt++;
    }
    return cnt;
}
int result(int idx, int x, int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=N||ny>=N)continue;
        if(s[idx].count(a[ny][nx]))
            cnt++;
    }
    return !cnt?0:pow(10,cnt-1);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N*N;i++){
        int idx;
        cin>>idx;
        v.push_back(idx);
        for(int j=0;j<4;j++){
            int n;
            cin>>n;
            s[idx].insert(n);
        }
    }
    for(int i=0;i<v.size();i++){
        int n=v[i], res=-1,blank=-1,x=-1,y=-1;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(a[j][k])continue;
                int love=result(n,k,j);
                int blankResult=check(k,j);
                if(res<love){
                    x=k, y=j;
                    res=love;
                    blank=blankResult;
                }
                else if(res==love && blank<blankResult){
                    x=k, y=j;
                    res=love;
                    blank=blankResult;
                }
            }
        }
        a[y][x]=n;
    }
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans+=result(a[i][j],j,i);
        }
    }
    cout<<ans;
}