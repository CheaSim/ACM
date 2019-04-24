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

int n;
const int maxn = 65e5+10;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    ll ans = 0;
    scanf("%d",&n);
    scanf("%s",s);
    per(i,0,n){
        if((s[i]-'0')%2==0){
            ans += 1ll * (i+1);
        }
    }
    printf("%lld\n",ans);

    return 0;
}
