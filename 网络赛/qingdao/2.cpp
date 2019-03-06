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
int T;
const int maxn = 1e5 + 10;
char s[maxn];
int t1[maxn];
int t2[maxn];
ll bit[maxn];
int lowbit(int x){
    return x&-x;
}
int n;
ll sum(int x){
    ll res = 0;
    for(int i=x;i;i-=lowbit(i)){
        res += bit[i];
    }
    return res;
}
void add(int x,ll val){
    for(int i=x;i<=n;i+=lowbit(i)){
        bit[i] += val;
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        memset(t1,0,sizeof(t1));
        memset(bit,0,sizeof(bit));
        scanf("%s",s);n = strlen(s);
        rep(i,0,n) s[i] -= '0';
        int now = 0;int sumt = 0;
        ll ans = 0;
        rep(j,0,n){
            sumt = 0;
            now = 0;
            rep(i,j,n){
                int light = s[i]^now;
                if(light == 0) now ^=1,sumt++;
                sumt++;
                t1[i] = sumt;
                ans += sumt;
                now ^= 1;
            }
        }
        printf("%lld\n",ans);

    }

    return 0;
}
