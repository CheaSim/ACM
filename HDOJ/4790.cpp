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
ll a,b,c,d,m,p;
ll getx1(ll lim){
    ll t = lim/p;
    if(t*p+m>lim) t--;
    return t;
}
ll getx2(ll lim){
    ll t = lim/p;
    if(t*p+m<lim) t++;
    return t;
}
ll getAns(ll x1,ll x2,ll t){
    if(x2<x1) return 0;
    ll ans = (x1*p+2ll*m+x2*p-2ll*t+2ll)*(x2-x1+1ll)/2ll;
    return ans;
}
ll getAns3(ll x1,ll x2,ll t){
    if(x2<x1) return 0;
    ll ans = (2ll*t-x1*p-x2*p-2ll*m+2ll)*(x2-x1+1ll)/2ll;
    return ans;
}
ll getAns2(ll x1,ll x2,ll t){
    if(x2<x1) return 0;
    ll ans = (2ll*t+2ll)*(x2-x1+1ll)/2ll;
    return ans;
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&m);
        if(b+c>a+d){
            swap(a,c); swap(b,d);
        }
        ll st = getx2(a+c),ed = getx1(b+d);
        ll ans = 0;
        ll x1 = getx1(b+c), x2 = getx2(a+d);
        ans += getAns(st,x1,a+c);
        ll temp1 = x2;
        while(temp1<=x1) temp1++;
        ans += getAns3(temp1,ed,b+d);
        ans += getAns2(x1+1,x2-1,b-a);
        ll ans2 = (d-c+1)*(b-a+1);
        ll temp = gcd(ans2,ans);
        ans /= temp; ans2 /= temp;
        printf("Case #%d: %lld/%lld\n",test_case,ans,ans2);
    }

    return 0;
}
