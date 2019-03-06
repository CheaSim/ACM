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
ll n,c,b;
const int maxn = 1e3;
ll a[maxn];
ll t[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(scanf("%lld%lld%lld",&n,&b,&c)!=EOF){
        rep(i,0,n) scanf("%lld",a+i);
        ll ans = 0;
        sort(a,a+n);
        rep(i,0,n){
            rep(j,i+1,n){
                if((a[j]-a[i]) % b == c)
                    ans++;
            }
        }
        printf("%lld\n",ans);
    }


    return 0;
}
