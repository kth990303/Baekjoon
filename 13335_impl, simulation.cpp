// 220127 #13335 트럭 Silver I
// impl, simulation
#include <bits/stdc++.h>
#define int long long
#define sz(v) (int)v.size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int,pi> pii;
const int MAX = 1e3+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N,W,L,now,a[MAX],ans,st[MAX]={1,},topidx,lastidx;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>W>>L;
    for (int i = 0; i < N; i++) {
        cin>>a[i];
    }
    // 제한이 작아서 시뮬레이션 돌림
    // ans: 현재 단위시간
    for (ans = 1;; ans++) {
        if(ans-st[topidx]>=W)now-=a[topidx++]; // topidx: 다리를 완전히 건넌 기차의 번호
        if(topidx==N)break; // topidx가 N이면 모두 건넌 것이므로 답 출력
        if(lastidx<N && now+a[lastidx]<=L){ // lastidx: 다리를 건너기 시작한 기차의 번호
            now+=a[lastidx];
            st[lastidx]=ans;
            lastidx++;
        }
    }
    cout<<ans;
}