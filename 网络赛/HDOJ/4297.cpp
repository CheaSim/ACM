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
const int maxn = 5e5+100;
struct node{
    int next,to;
}G[maxn<<1];
int cnt;
pII ans[maxn];
int head[maxn];
void addedge(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
struct LCA{
    int ln;
    int fa[maxn],dep[maxn];
    struct node1{
        int to,next,id;
    }query[maxn<<1];
    int tot,pre[maxn],vis[maxn],headq[maxn];
    void init(int n){
        ln = n;
        tot = 0;
        memset(headq,-1,sizeof(headq));
        memset(dep,0,sizeof(dep));
        rep(i,1,n+1) fa[i] = i;
    }
    void add_ask(int u,int v,int id){
        query[tot].id = id;
        query[tot].to = v;
        query[tot].next = headq[u];
        headq[u] = tot++;
    }
    int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
    void addquery(int u,int v,int id){
        add_ask(u,v,id);
        add_ask(v,u,id);
    }
    void dfs(int u,int deep,int fa,int rt){
        dep[u] = deep;
        for(int i=head[u];~i;i=G[i].next){
            int v = G[i].to;
            if(v==fa) continue;
            if(vis[v]==0){
                dfs(v,deep+1,u);
                fa[v] = u;
            }
        }
        vis[u] = rt;
        for(int i=headq[u];~i;i=query[i].next){
            int v = query[i].to;
            if(vis[v]==rt){
                int x = find(v);
                int dis = dep[v]+dep[u]-2*dep[x];
                ans[query[i].id].fi = dis - dis/2;
                ans[query[i].id].se = dis/2;
            }else{
                ans[query[i].id].fi = ans[query[i].id].se = -1;
            }
        }
    }
}



