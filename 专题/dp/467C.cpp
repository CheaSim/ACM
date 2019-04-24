#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define debug(x) cout<<"debug:"<<x<<endl;
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
int n,m,k;
const int maxn = 5e3+10;
ll dp[maxn][maxn];
ll a[maxn];
ll sum[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n+1) scanf("%lld",a+i);
    rep(i,0,n+1) sum[i] = sum[i-1]+a[i];

    dp[m][1] = sum[m];
    rep(i,m+1,n+1){
        rep(j,1,k+1){
            dp[i][j] = max(dp[i-1][j],dp[i-m][j-1] + sum[i] - sum[i-m]);
        }
    }
    printf("%lld\n",dp[n][k]);

    return 0;
}
