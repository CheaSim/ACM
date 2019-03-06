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
const int maxn = 5e5 + 10;
ll n,T;
ll x[maxn],a[maxn],suma[maxn],sumt[maxn];
ll getl(ll l,ll r){
    return (sumt[r]-sumt[l-1]) - (suma[r]-suma[l-1])*x[l];
}
ll getr(ll l,ll r){
    return (suma[r]-suma[l-1])*x[r] - (sumt[r]-sumt[l-1]);
}
bool check(ll ans){
    ll l,r,mid,mida;
    mida = ans/2+1;
    l = r = mid = 1;
    while(1){
        while(r<=n && suma[r]-suma[l-1]<ans) r++;
        while(mid<r && suma[mid]-suma[l-1]<mida) mid++;
        if(r>n || mid>n) break;
        ll temp = suma[r]-suma[l-1]-ans;
        if(getr(l,mid)+getl(mid,r)-temp*(x[r]-x[mid]) <= T) return true;
        l++;
    }
    l = r = mid = n;
    while(1){
        while(l>=1 && suma[r]-suma[l-1]<ans) l--;
        while(mid>l && suma[r]-suma[mid-1]<mida) mid--;
        if(l<1 || mid<1) break;
        ll temp = suma[r] - suma[l-1] - ans;
        if(getr(l,mid)+getl(mid,r)-temp*(x[mid]-x[l])<=T) return true;
        r--;
    }
    return false;
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%lld%lld",&n,&T); T>>=1;
    rep(i,1,n+1) scanf("%lld",x+i);
    rep(i,1,n+1){
        scanf("%lld",a+i);
        suma[i] = suma[i-1] + a[i];
        sumt[i] = sumt[i-1]+a[i]*x[i];
    }
    ll l,r,mid,ans;
    l = 1;r = suma[n];
    while(l<=r){
        mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;l = mid+1;
        }else {
            r = mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
