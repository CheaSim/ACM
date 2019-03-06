#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
int n,m,k,l;
const int maxn = 1e3 + 10;
int a[maxn],b[maxn],c[maxn];
int dp[maxn][220];
// op
int dfs(int pos,int val){
    if(pos == n){
        if(val >= k){
            return 2;
        }else if(val > l){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[pos][val] != -1) return dp[pos][val];
    if(pos%2==0){
        int res = 0;
        int mmin = min(200,val+a[pos]);
        int mmax = max(0,val-b[pos]);
        if(a[pos]) res = max(res,dfs(pos+1,mmin));
        if(b[pos]) res = max(res,dfs(pos+1,mmax));
        if(c[pos]) res = max(res,dfs(pos+1,200-val));
        return dp[pos][val] = res;
    }else{
        int res = 2;
        int mmin = min(200,val+a[pos]);
        int mmax = max(0,val-b[pos]);
        if(a[pos]) res = min(res,dfs(pos+1,mmin));
        if(b[pos]) res = min(res,dfs(pos+1,mmax));
        if(c[pos]) res = min(res,dfs(pos+1,200-val));
        return dp[pos][val] = res;
    }
}
int main(){
#ifdef LOCAL
    freopen("b.in","r",stdin);
#endif // LOCAL
    rep(i,0,maxn) rep(j,0,220) dp[i][j] = -1;
    scanf("%d%d%d%d",&n,&m,&k,&l);
    l += 100; k += 100; m += 100;
    rep(i,0,n){
        scanf("%d%d%d",a+i,b+i,c+i);
    }
    int op = dfs(0,m);
    if(op==2) puts("Good Ending");
    else if(op==1) puts("Normal Ending");
    else puts("Bad Ending");
    return 0;
}
