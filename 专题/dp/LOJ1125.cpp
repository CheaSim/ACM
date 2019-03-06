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

ll n,m,q;
ll d;
const int maxn = 210;
ll num[maxn];
ll dp[maxn][12][22];
ll a[maxn];
ll MOD(ll x,ll mod){
    ll tx = x % mod;
    if(tx<0) tx += mod;
    return tx;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%lld%lld",&n,&q);
        rep(i,1,n+1) scanf("%lld",num+i);
        printf("Case %d:\n",test_case);
        while(q--){
            scanf("%lld%lld",&d,&m);
            rep(i,1,n+1) a[i] = MOD(num[i],d);
            memset(dp,0,sizeof(dp));
            rep(i,0,n) dp[i][0][0] = 1;
            rep(i,1,n+1){
                rep(j,1,m+1){
                    rep(k,0,d) dp[i][j][k] = dp[i-1][j][k];
                    rep(k,0,d){
                        dp[i][j][(k+a[i])%d] += dp[i-1][j-1][k];
                    }
                }
            }
            printf("%lld\n",dp[n][m][0]);
        }
    }
    return 0;
}
