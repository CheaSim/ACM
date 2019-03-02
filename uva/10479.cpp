#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
ll n;
ll lie[10][20] ={ {0}, {1}, {0,2}, {1,0,0,3},{0,2,1,1,0,0,0,4}};
ll solve(ll x,int dep){
    if(dep<5){
        return lie[dep][x];
    }
    ll st = 0;
    rep(i,2,dep+1){
        ll temp = pow(2,dep-i-1);
        if(i==dep) temp = 1;
        if(x<temp*(1ll*i-1ll)+st) return solve((x-st)%temp,dep-i);
        st += temp*(ll)(i-1);
    }
    return dep;
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n && n){
        int dep = 0;ll temp = 1;
        n--;
        ll tn = n;
        while(tn) tn/=2,dep++;
        temp<<=(dep-1);
        n = n - temp;
        cout<<solve(n,dep);
        cout<<'\n';
    }

    return 0;
}
