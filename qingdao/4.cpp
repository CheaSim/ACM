#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
template <typename T>  
inline bool read (T &ret) {  
    char c;  
    int sgn;  
    if (c = getchar(), c == EOF) return 0; //EOF  
    while (c != '-' && (c < '0' || c > '9') ) {
        if((c = getchar()) == EOF) return 0;
    }
    sgn = (c == '-') ? -1 : 1;  
    ret = (c == '-') ? 0 : (c - '0');  
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');  
    ret *= sgn;  
    return 1;  
}  
template<typename T>
void print(T x) {
    static char s[33], *s1; s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) putchar('-'), x = -x;
    while(x) *s1++ = (x % 10 + '0'), x /= 10;
    while(s1-- != s) putchar(*s1);
}
template<typename T>
void println(T x) {
    print(x); putchar('\n');
}
//head
int T,n,m,q,tot;
const int maxn = 1e5 + 10;
struct node{
    int next,to;
    ll val;
}G[maxn<<1];
int head[maxn];
int red[maxn];
void addedge(int u,int v,ll val){
    G[tot].to = v;
    G[tot].next = head[u];
    G[tot].val = val;
    head[u] = tot++;
}
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(red,0,sizeof(int)*(n+2));
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&q);
        init();
        rep(i,1,m+1){
            int x;read(x);
            red[x] = 1;
        }
        rep(i,0,n-1){
            int u,v; ll val;read(u);read(v);read(val);
            addedge(u,v,val);addedge(v,u,val)nm ;
        }
        while(q--){
            int k;scanf("%d",&k);
            rep
        }
    }


    return 0;
}
