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

int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        ll x;scanf("%lld",&x);
        int t=0;
        while(x){
            if(x&1) t++;
            x>>=1;
        }
        ll ans = 1;
        while(t--) ans = ans *2;
        cout<<ans<<endl; 
    }
    return 0;
}
