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

const int maxn = 1e5+10;
int a[maxn];
int sum[maxn];
int cnt[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int n,k;scanf("%d%d",&n,&k);
    ll ans = 0;
    rep(i,1,n+1){
        scanf("%d",a+i);
        sum[i] = (sum[i-1] + a[i])%k;
        ans += cnt[sum[i]];
        cnt[sum[i]] ++;
    }
    printf("%lld\n",ans+cnt[0]);
    return 0;
}
