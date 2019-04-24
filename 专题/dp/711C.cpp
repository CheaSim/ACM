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
const int maxn = 1e2+10;
int n,m,k;
ll dp[maxn][maxn][maxn];
ll c[maxn];
ll p[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n+1) scanf("%lld",c+i);
    rep(i,1,n+1) rep(j,1,m+1) scanf("%lld",&p[i][j]);
    rep(i,0,maxn) rep(j,0,maxn) rep(z,0,maxn) dp[i][j][z] = 1e17;
    if(c[1] > 0) dp[1][1][c[1]] = 0;
    else {
        rep(i,1,m+1) dp[1][1][i] = p[1][i];
    }
    rep(i,2,n+1){
        rep(j,1,k+1){
            rep(z,1,m+1){
                if(c[i] > 0){
                    if(z != c[i])
                        dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i-1][j-1][z]);
                    else
                        dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
                }else{
                    rep(x,1,m+1){
                        if(x != z){
                            dp[i][j][x] = min(dp[i][j][x],dp[i-1][j-1][z]+ p[i][x]);
                        }else{
                            dp[i][j][x] = min(dp[i][j][x],dp[i-1][j][z] + p[i][x]);
                        }
                    }
                }
            }
        }
    }
    ll ans = 1e17;
    rep(i,1,m+1) {
        ans = min(ans,dp[n][k][i]);
    }
    if(ans == 1e17) ans = -1;
    printf("%lld\n",ans);

    return 0;
}
