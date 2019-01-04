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
inline void Swap(int &a,int &b){
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
void addedge(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
void DFS1(int u, int f, int d)
{
    dep[u] = d; fa[u] = f; size[u] = 1; son[u] = -1;
    for(int i = head[u]; i != -1; i = G[i].next)
    {
        int v = G[i].to;
        if(v == f) continue;
        DFS1(v, u, d+1);
        size[u] += size[v];
        if(son[u] == -1 || size[son[u]] < size[v])
            son[u] = v;
    }
}
void dfs2(int u,int topu){
    top[u] = topu;
    id[u] = ++totw;
    if(son[u] == -1) return;
    dfs2(son[u],top[u]);
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa[u] || v==son[u]) continue;
        dfs2(v,v);
    }
}
void change(int u, int v, ll z, int op)
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(u, v);
            swap(f1, f2);
        }
        ans[id[f1]] += z; ans[id[u]+1] -= z;
        //Pl(Ans[pos[f1]]);
        u = fa[f1], f1 = top[u];
    }
    if(op == 2 && u == v) return ;
    if(dep[u] > dep[v]) swap(u, v);
    if(op == 1) {ans[id[u]] += z, ans[id[v]+1] -= z;}
    else {ans[id[son[u]]] += z; ans[id[v]+1] -= z;}
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
    memset(ans,0,sizeof(ans));
}
char op[20];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;read(T);
    rep(test_case,1,T+1){
        scanf("%d%d",&n,&m);
        init();
        rep(i,0,n-1){
            scanf("%d%d",from+i,to+i);
            addedge(from[i],to[i]); addedge(to[i],from[i]);
        }
        DFS1(1,-1,1);
        dfs2(1,1);
        rep(i,0,m){
            scanf("%s",op);
            scanf("%d%d%lld",&ask[i].u,&ask[i].v,&ask[i].val);
            if(op[3]=='1') ask[i].op = 1;
            else ask[i].op = 2;
        }
        rep(i,0,m){
            if(ask[i].op==2) continue;
            change(ask[i].u,ask[i].v,ask[i].val,1);
        }
        rep(i,1,totw+1) ans[i] += ans[i-1];
        printf("Case #%d:\n",test_case);
        rep(i,1,n+1){
            printf("%lld%c",ans[id[i]],i==n?'\n':' ');
        }
        memset(ans,0,sizeof(ans));
        rep(i,0,m){
            if(ask[i].op==1) continue;
            change(ask[i].u,ask[i].v,ask[i].val,2);
        }
        rep(i,1,totw+1) ans[i] += ans[i-1];
        if(n==1) puts("");
        rep(i,0,n-1){
            if(dep[from[i]]>dep[to[i]]) Swap(from[i],to[i]);
            printf("%lld%c",ans[id[to[i]]],i==n-2?'\n':' ');
        }
    }

    return 0;
}
