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
ll a[maxn];
int n;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%lld",a+i);
    }
    ll ans = 0;
    ll last = 1e14;
    per(i,0,n){
        ans += max(0ll,min(last,a[i]));
        last = max(0ll,min(last,a[i]))-1;
    }
    printf("%lld\n",ans);
    return 0;
}
