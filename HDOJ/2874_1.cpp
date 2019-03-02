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
int n,m,c,cnt,tot;
const int maxn = 1e4+1000;
struct node{
    int next,to,val;
}G[maxn<<2];
int head[maxn],fa[maxn],vis[maxn],ans[maxn*200],dis[maxn],headq[maxn];
void add(int u,int v,int val){
    G[cnt].to = v;
    G[cnt].next = head[u];
    G[cnt].val = val;
    head[u] = cnt++;
}
struct Query{
    int next,to;
}query[maxn*200];
int find(int x){
    if(x!=fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void addq(int u,int v){
    query[tot].to = v;
    query[tot].next = headq[u];
    headq[u] = tot++;
}
void dfs(int now){
    vis[now] = 1;
    for(int i=headq[now];~i;i=query[i].next){
        int v = query[i].to;
        if(vis[v]){
            if(v==now){
                ans[i/2] = 0;
                continue;
            }
            if(find(v)==0) ans[i/2] = -1;
            else ans[i/2] = dis[now]+dis[v]-2*dis[find(v)];
        }
    }
    for(int i=head[now];~i;i=G[i].next){
        int v = G[i].to;
        if(vis[v]) continue;
        dis[v] = dis[now] + G[i].val;
        dfs(v);
        fa[v] = now;
    }
}
void init(){
    memset(head,-1,sizeof(int)*(n+2));
    memset(headq,-1,sizeof(int)*(n+2));
    memset(vis,0,sizeof(int)*(n+1));
    rep(i,1,n+1) fa[i] = i;
    cnt = 0;
    tot = 0;
}
void Union(int a,int b){
    int i = find(a), j = find(b);
    if(i==j) return;
    fa[i] = j;
}
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
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    while(~scanf("%d%d%d",&n,&m,&c)){
        init();
        rep(i,0,m){
            int u,v,val;read(u);read(v);read(val);
            add(u,v,val); add(v,u,val);
            Union(u,v);
        }
        rep(i,1,n+1){
            if(fa[i] == i) fa[i] = 0;
            add(0,i,0); add(i,0,0);
        }
        rep(i,0,c){
            int u,v; read(u); read(v);
            addq(u,v); addq(v,u);
        }
        rep(i,1,n+1) fa[i] = i;
        dfs(0);
        rep(i,0,c){
            if(ans[i]==-1){
                puts("Not connected");
                continue;
            }
            printf("%d\n",ans[i]);
        }
    }

    return 0;
}

