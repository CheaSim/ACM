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
int n,m,k;
const int maxm = 21;
const int maxn = 110;
int dp[1<<maxm];
int sta[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,0,n){
        rep(j,0,k){
            int x; scanf("%d",&x);
            dp[i] |= (1<<(x-1));
        }
    }
    rep(i,0,(1<<m)) dp[i] = INF;
    dp[0] = 0;
    for(int i = 0;i<(1<<m);i++){
        rep(j,0,n){
            dp[i|sta[j]] = min(dp[i]+1,dp[i|sta[j]]);
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
    return 0;
}
