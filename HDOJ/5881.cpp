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

ll l,r;
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>l>>r){
        if(r<=1) puts("0");
        else if(r<=2) puts("1");
        else if(l==0) printf("%lld\n",(r-1)/2+1);
        else {
            ll temp = r-l-3;
            temp = max(0ll,temp);
            ll ans = temp/2;
            if(ans*2<temp) ans++;
            printf("%lld\n",ans+2);
        }
    }

    return 0;
}
