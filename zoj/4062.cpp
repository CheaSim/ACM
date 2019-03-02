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
int n;
ll m;
const int maxn = 1e5+10;
ll a[maxn];

bool check(ll x){
    ll last = 0;
    ll tm = m;
    rep(i,0,n-2){
        ll temp = (x/a[i]);
        if(x > temp*a[i]) temp++;
        ll t = temp - last;
        if(t<=0) t = 1;
        last = t-1;
        tm -= (t*2-1);
        if(tm<=0) return false;
    }
    ll now1 = x/a[n-2];
    ll now2 = x/a[n-1];
    if(x > now1*a[n-2]) now1++;
    if(x > now2*a[n-1]) now2++;
    now1 -= last;
    if(now1<0) now1 = 1;
    if(now1>now2){
        tm -= (2*now1-1);
    }else if(now1==now2){
        tm -= (2*now1);
    }else{
        tm -= (2*now2);
    }
    if(tm<0) return false;
    return true;
}
ll solve(ll l,ll r){
    ll ans = 0;
    ll mid;
    while(l<=r){
        mid = l+r>>1;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&m);
        ll mmin = 1e15;
        rep(i,0,n){
            scanf("%lld",a+i);
            mmin = min(a[i],mmin);
        }
        printf("%lld\n",solve(mmin,(ll)mmin*m));
    }

    return 0;
}
