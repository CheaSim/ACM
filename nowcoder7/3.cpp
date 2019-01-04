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
const int N = (1<<18) + 10;
char dp[20][N];
bool B[22][N];
ll ans = 0;
void gen(int n){
    int pow3 = 1;
    rep(i,0,n) pow3*=3;
    rep(i,0,1<<(1<<n)){
        rep(k,0,1<<n){
            if(i&(1<<k)) B[n][k] = 1;
            else B[n][k] = 0;
        }  
        rep(j,0,pow3){
            int cur = j;
            per(k,0,n){
                int z = cur%3;
                rep(l,0,1<<k){
                    if(z==0) B[k][l] = B[k+1][2*l] & B[k+1][2*l+1];
                    else if(z==1) B[k][l] = B[k+1][2*l]^B[k+1][2*l+1];
                    else B[k][l] = B[k+1][2*l]|B[k+1][2*l+1];
                }
                cur /= 3;
            }
            dp[n][i] += B[0][0];
        }
    }
}
void dfs(int n){
    if(n<=4){
        int bit = 0;
        rep(i,0,1<<n){
            if(B[n][i]) bit^=(1<<i);
        }
        ans += dp[n][bit];
        return ;
    }
    rep(i,0,3){
        rep(j,0,1<<(1<<(n-1))){
            if(i==0) B[n-1][j] = B[n][2*j]&B[n][2*j+1];
            else if(i==1) B[n-1][j] = B[n][2*j]^B[n][2*j+1];
            else B[n-1][j] = B[n][2*j]|B[n][2*j+1];
        }
        dfs(n-1);
    }
}
char s[N];
int main(){  
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int n;
    scanf("%d",&n); scanf("%s",s);
    rep(i,0,4+1) gen(i);
    rep(i,0,1<<n) B[n][i] = s[i]-'0';
    dfs(n);
    printf("%lld\n",ans);
    return 0;
}
