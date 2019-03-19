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

int n,k;
const int maxn = 1e5+10;
int dp[maxn][2];
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("5.in","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    int mmax = 0;
    int mmin = INF;
    rep(i,0,n){
        int x; scanf("%d",&x);
        a[x] ++;
        mmax = max(mmax,x);
        mmin = min(mmin,x);
    }
    if(k>mmax-mmin) {
        cout<<n<<'\n';
        return 0;
    }
    if(k==0){
        int cnt = 0;
        rep(i,mmin,mmax+1) if(a[i] > 0) cnt++;
        cout<<cnt<<'\n';
        return 0;
    }
    int ans = 0;
    rep(i,mmin,k+mmin){
        int temp = 0;
        for(int j=i;j<=mmax;j+=k){
            if(j-k>=mmin){
                dp[j][0] = dp[j-k][1];
                dp[j][1] = dp[j-k][0] + a[j];
            }else{
                dp[j][0] = 0;
                dp[j][1] = a[j];
            }
            temp = max(dp[j][0],dp[j][1]);
        }
        ans += temp;
    }
    printf("%d\n",ans);

    return 0;
}
