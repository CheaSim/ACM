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
const int maxn = 110;
struct node{
    char s[20];
    ll val;
    bool operator<(const node &x) const{
        if(val==x.val){
            int cmp = strcmp(s,x.s);
            if(cmp>=0) return false;
            return true;
        }
        return val>x.val;
    }
}w[maxn];
int n,m;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        rep(i,0,n){
            scanf("%s",w[i].s);
            scanf("%lld",&w[i].val);
        }
        sort(w,w+n);
        ll ans = 0;
        rep(i,0,m) ans += w[i].val*(ll)(m-i);
        printf("%lld ",ans);
        rep(i,0,m){
            printf("%s%c",w[i].s,i==m-1?'\n':' ');
        }
    }

    return 0;
}
