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

const int maxm = 1e3+10;
int dp[maxm][15][15];
char s[20];
int m;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%s",s);
    scanf("%d",&m);
    int n = strlen(s);
    rep(i,1,n+1) if(s[i] == '1') dp[0][i][i] = 1; 
    rep(i,1,m){
        rep(j,1,n+1){
            rep(k,1,n+1){
                if(dp[i-1][j][k]){
                    for(int z = j+1;z+j<=n;z++){
                        if(z == k) continue;
                        if(s[z] == '1'){
                            dp[i][z+j][z] = 1;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,1,n+1) rep(j,1,n+1) if(dp[m-1][i][j]) ans = 1;
    cout<<ans<<endl;
    if(ans) puts("YES");
    else puts("NO");

    return 0;
}
