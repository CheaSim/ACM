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
ll st,ed,t;
int n;
const int maxn = 1e5+10;
ll p[maxn];
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    scanf("%lld%lld%lld",&st,&ed,&t);
    scanf("%d",&n);
    rep(i,0,n) scanf("%lld",p+i),p[i]-=st;
    ed -= st;
    ll ans = 1e13;
    ll wait = 1e14;
    int cnt = 0;
    rep(i,0,n){
        if( (ll)(i+1)*t>ed || p[i]+t>ed) break;
        cnt++;
        if(p[i] > (ll)(i)*t && p[i]+t<=ed){
            ans = p[i]-1;
            cout<<ans+st<<'\n';
            return 0;
        }else{
            ll temp = (ll)(i)*t - p[i];
            if(wait > temp){
                wait = temp;
                ans = p[i]-1ll;
            }
        }
    }
    ll temp = (ll)(cnt+1)*t; if(temp<=ed) ans = temp-t;
    printf("%lld\n",ans+st);

    return 0;
}
