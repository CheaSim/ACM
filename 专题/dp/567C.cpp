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
const int maxn = 2e5+10;
int n,k;
map<pair<int,int>,ll> dp;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    rep(i,1,n+1) scanf("%d",a+i);
    ll ans = 0;
    rep(i,1,n+1){
        per(j,0,min(i,3)){
            if(a[i] % (int)pow(k,j) == 0){
                if(j==0) dp[make_pair(a[i]/pow(k,j),j)]++;
                if(j==1) dp[make_pair(a[i]/pow(k,j),j)] += dp[make_pair(a[i]/pow(k,j),0)];
                if(j==2) ans += 1LL*dp[make_pair(a[i]/pow(k,2),1)]; 
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
