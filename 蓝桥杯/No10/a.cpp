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

bool check(int x){
    while(x){
        int t = x % 10;
        x /= 10;
        if(t == 1 || t == 0 || t == 9 || t == 2) return true;
    }
    return false;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    ll ans = 0;

    rep(i,1,2019+1){
        if(check(i)) ans += 1ll * i*i;
    }
    printf("%lld\n",ans);
    return 0;
}
