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
ll a[maxn];
int T,n;
pair<ll,int> dp[maxn][2];
ll inf = 1ll<<60;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n+1) scanf("%lld",a+i);
        dp[0][0] = make_pair(0,0);
        dp[0][1] = make_pair(inf,0);
        rep(i,1,n+1){
            dp[i][0] = min(dp[i-1][0],make_pair(dp[i-1][1].fi-a[i],dp[i-1][1].se+1));
            dp[i][1] = min(dp[i-1][1],make_pair(dp[i-1][0].fi+a[i],dp[i-1][0].se+1));
        }
        printf("%lld %d\n",-dp[n][0].fi,dp[n][0].se);
    }
    return 0;
}
