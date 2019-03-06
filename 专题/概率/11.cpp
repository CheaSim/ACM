#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
int n,m;
const int maxn = 1e5 + 10;
double dp[maxn];
int nxt[maxn];
int main(){
#ifdef LOCAL
    freopen("11.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) && (m||n)){
        rep(i,0,n+1) dp[i] = 0.0,nxt[i] = 0;
        rep(i,0,m){
            int x,y;scanf("%d%d",&x,&y);
            nxt[x] = y;
        }
        per(i,0,n){
            if(nxt[i]){
                dp[i] = dp[nxt[i]];
            }else{
                double sum = 0.0;
                rep(j,1,6+1){
                    if(i+j<=n){
                        sum+=dp[i+j];
                    }
                }
                dp[i] = sum/6.0+1.0;
            }
        }
        printf("%0.4f\n",dp[0]);
    }

    return 0;
}
