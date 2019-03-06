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
const int maxn = 1e5 + 10;
int n,m;
ll p[maxn],q[maxn],s[maxn];
ll mmax[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        rep(i,0,n) scanf("%d%d",s+i,p+i);
        rep(i,0,m) scanf("%d",q+i);
        mmax[n-1] = s[n-1]*p[n-1];
        mmax[n] = 1e18+1;
        s[n] = s[n-1];
        per(i,0,n-1) mmax[i] = min(s[i]*p[i],mmax[i+1]);
        rep(i,0,m){
            ll query = q[i];
            int pos = lower_bound(s,s+n,q[i]) - s;
            ll ans = min(mmax[pos],query*p[pos-1]);
            printf("%lld\n",ans);
        }
    }


    return 0;
}
