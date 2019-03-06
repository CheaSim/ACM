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
int n,k;
const ll mod = 1e9+7;
ll pow3(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ans;
}
ll k2,kk2,kk1;
ll solve(int n,int k){
    if(k==1) return 2;
    if(n==1) return k2;
    if(n==2) return k2*kk1%mod;
    ll res = (k2*kk2%mod)*pow3(kk1,n-2)%mod;
    res = (res+solve(n-2,k))%mod;
    return res;
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        k2 = pow3(2,k);
        kk1 = (k2-1+mod)%mod;
        kk2 = (k2-2+mod)%mod;
        printf("%lld\n",solve(n,k));
    }

    return 0;
}
