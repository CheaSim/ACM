#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 5e4+10;
int size[maxn],dep[maxn],top[maxn],fa[maxn],id[maxn],son[maxn];
int head[maxn],w[maxn];
int n,cnt,totw,m;
struct edge{
    int next,to;
}G[maxn<<1];
int find(int x){ return x==fa[x]?x:find(fa[x]);}
void addedge(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
void dfs1(int u,int f){
    size[u] = 1;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==f) continue;
        dep[v] = dep[u]+1;
        fa[v] = u;
        dfs1(v,u);
        if(size[v] > size[son[u]]) son[u] = v;
        size[u]+=size[v];
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
int data[maxn<<2],lazy[maxn<<2];
void pushdown(int rt){
    if(lazy[rt]!=0){
        data[rt<<1] += lazy[rt];
        data[rt<<1|1] += lazy[rt];
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int l,int r,int rt){
    lazy[rt] = 0;
    if(l==r){
        data[rt] = w[l];
        return;
    }
    int mid = l+r>>1;
    build(lson); build(rson);
}
int query(int pos,int l,int r,int rt){
    if(l==r && l==pos) return data[rt];
    int mid = l+r>>1;
    pushdown(rt);
    if(pos<=mid) return query(pos,lson);
    else return query(pos,rson);
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        lazy[rt] += val;
        data[rt] += val;
        return;
    }
    pushdown(rt);
    int mid = l+r>>1;
    if(L<=mid) update(val,L,R,lson);
    if(mid<R) update(val,L,R,rson);
}
void change(int u,int v,int val){
    int t1=top[u],t2=top[v];
    while(t1!=t2){
        if(dep[t1]<dep[t2]){
            swap(t1,t2);
            swap(u,v);
        }
        update(val,id[t1],id[u],1,totw,1);
        u = fa[t1];
        t1 = top[u];
    }
    if(dep[u]>dep[v]) swap(u,v);
    update(val,id[u],id[v],1,totw,1);
}
int val[maxn];
int p;
char op[20];
void init(){
    cnt = totw = 0;
    memset(head,-1,sizeof(head));
    dep[1] = fa[1] = size[0] = 0;
    memset(son,0,sizeof(son));
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    while(~scanf("%d%d%d",&n,&m,&p)){
        init();
        rep(i,1,n+1) scanf("%d",val+i);
        rep(i,0,m){
            int u,v;scanf("%d%d",&u,&v);
            addedge(u,v); addedge(v,u);
        }
        dfs1(1,0);
        dfs2(1,1);
        rep(i,1,n+1) w[id[i]] = val[i];
        build(1,totw,1);
        while(p--){
            scanf("%s",op);
            if(op[0]=='Q'){
                int x;scanf("%d",&x);
                printf("%d\n",query(id[x],1,totw,1));
            }else{
                int u,v,val;scanf("%d%d%d",&u,&v,&val);
                if(op[0]=='D') val = -val;
                change(u,v,val);
            }
        }
    }

    return 0;
}
