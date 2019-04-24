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
const int maxn = 1e6+10;
const ll mod = 1e9+7;
ll a[maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%lld",&n);
    rep(i,1,n+1) scanf("%lld",a+i);
    ll ans = 0;
    rep(i,1,n+1){
        ll t = (n-i+1)*(n-i+2)/2ll%mod;
        ans += (i*a[i]%mod)*t%mod;
        ans %= mod;
    }
    printf("%lld\n",ans);

    return 0;
}
