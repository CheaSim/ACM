#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head-------------------------------------------
const int maxn = 1e4+10;
const int maxm = 1e2+5;
const int mod = 123456789;
int n,m;
int lowbit(int x){
    return x&-x;
}
int bit[maxn][maxm],a[maxn],dp[maxn][maxm];
int add(int x,int val,int t){
    for(int i=x;i<=n;i+=lowbit(i)){
        bit[i][t] += val;
        bit[i][t] %= mod;
    }
}
int query(int x,int t){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)){
        res = (res+bit[i][t])%mod;
    }
    return res;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)){
        memset(bit,0,sizeof(bit));
        memset(dp,0,sizeof(dp));
        vector<int> ve;
        rep(i,0,n+1){
            dp[i][1] = 1;
        }
        rep(i,1,n+1){
            int x;scanf("%d",a+i);
            ve.push_back(a[i]);
        }
        sort(ve.begin(),ve.end());
        ve.erase(unique(ve.begin(),ve.end()),ve.end());
        int len = ve.size();
        rep(i,1,n+1){
            a[i] = lower_bound(ve.begin(),ve.end(),a[i])-ve.begin()+1;
        }
        int ans = 0;
        rep(i,1,n+1){
            rep(j,1,m+1){
                dp[i][j] += query(a[i]-1,j-1);
                dp[i][j] %= mod;
                add(a[i],dp[i][j],j);
            }
            ans += dp[i][m] % mod;
            ans %= mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
