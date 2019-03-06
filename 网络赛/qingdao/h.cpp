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

const int maxn = 1e5 + 10;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("h.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len = strlen(s);
        ll ans = 0; ll w = 0;
        if(s[0]=='1') ans = w = 1;
        else ans = w = 2;
        rep(i,1,len){
            if(s[i]==s[i-1]) w += i*2;
            else w += i*1;
            if(s[i]=='1') w += 1;
            else w += 2;
            ans += w;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
