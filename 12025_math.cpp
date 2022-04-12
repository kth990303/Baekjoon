#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll k,cnt=1;
vector<int> v,idx;
void solve(){
    ll tmp=k-1;
    int i=0;
    for(;tmp;i++){
        if(tmp%2)v.push_back(i);
        tmp/=2;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>s>>k;
    string ss=s;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='1'||s[i]=='2'||s[i]=='6'||s[i]=='7'){
            idx.push_back(i);
            cnt*=2;
            if(s[i]=='7')ss[i]='2';
            else if(s[i]=='6')ss[i]='1';
        }
    }
    if(k>cnt){
        cout<<-1;
        return 0;
    }
    solve();
    for(int i=0;i<v.size();i++){
        if(ss[idx[v[i]]]=='1')ss[idx[v[i]]]='6';
        else if(ss[idx[v[i]]]=='2')ss[idx[v[i]]]='7';
    }
    cout<<ss;
}