#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
template<typename T>
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
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
inline void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
const int maxn = 1e5+100;
int size[maxn],dep[maxn],top[maxn],fa[maxn],id[maxn],son[maxn],w[maxn];
int head[maxn];
ll ans[maxn];
int cnt,totw,n,m;
struct edge{
    int next,to;
}G[maxn<<1];
int find(int x){ return x==fa[x]?x:find(fa[x]);}
void addedge(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
void dfs1(int u){
    size[u] = 1;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(fa[u]==v) continue;
        dep[v] = dep[u]+1;
        fa[v] = u;
        dfs1(v);
        if(size[v]>size[son[u]]) son[u] = v;
        size[u] += size[v];
    }
}
void dfs2(int u,int topu){
    top[u] = topu;
    id[u] = ++totw;
    if(son[u]) dfs2(son[u],top[u]);
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa[u] || v==son[u]) continue;
        dfs2(v,v);
    }
}
void change(int u,int v,ll val,int op){
    int t1=top[u], t2 = top[v];
    while(t1!=t2){
        if(dep[t1]<dep[t2]){
            swap(t1,t2); swap(u,v);
        }
        ans[id[t1]] += val; ans[id[u]+1] -= val;
        u = fa[t1];
        t1 = top[u];
    }
    if(op==2 && u==v) return;
    if(dep[u]>dep[v]) swap(u,v);
    if(op==1){
        ans[id[u]] += val; ans[id[v]+1] -= val;
    }else{
        ans[id[son[u]]] += val; ans[id[v]+1] -= val;
    }
}
struct node{
    int op,u,v;
    ll val;
    bool operator<(const node &x){
        return op < x.op;
    }
}ask[maxn];
int from[maxn],to[maxn];
void init(){
    memset(head,-1,sizeof(head));
    cnt = totw = 0;
    dep[1] = fa[1] = size[0] = 0;
    memset(son,0,sizeof(son));
    memset(ans,0,sizeof(ans));
}
char op[20];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;read(T);
    rep(test_case,1,T+1){
        read(n);read(m);
        init();
        rep(i,0,n-1){
            read(from[i]); read(to[i]);
            addedge(from[i],to[i]); addedge(from[i],to[i]);
        }
        dfs1(1);
        dfs2(1,1);
        rep(i,0,m){
            scanf("%s",op);
            read(ask[i].u);read(ask[i].v);read(ask[i].val);
            ask[i].op = op[3]-'0';
        }
        int u,v; ll val;
        sort(ask,ask+m);
        int sign = 0;
        rep(i,0,m){
            if(ask[i].op==2){
                sign = i;
                break;
            }
            u = ask[i].u,v = ask[i].v;val = ask[i].val;
            change(u,v,val,1);
        }
        rep(i,1,totw+1) ans[i] += ans[i-1];
        printf("Case #%d:\n",test_case);
        rep(i,1,n+1){
            printf("%lld%c",ans[id[i]],i==n?'\n':' ');
        }
        memset(ans,0,sizeof(ans));
        rep(i,sign,m){
            u = ask[i].u,v = ask[i].v;val = ask[i].val;
            change(u,v,val,2);
        }
        rep(i,1,n+1) ans[i] += ans[i-1];
        rep(i,0,n-1){
            if(dep[from[i]]>dep[to[i]]) swap(from[i],to[i]);
            printf("%lld%c",ans[id[to[i]]],i==n-2?'\n':' ');
        }
    }

    return 0;
}
