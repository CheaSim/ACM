#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 4e4+100;
struct Query{
    int to,id;
    Query(){}
    Query(int a,int b){
        to = a;id = b;
    }
};
vector<Query> query[maxn];
struct node{
    int to,next,val;
}G[maxn<<2];
int n,m,cnt;
int head[maxn],vis[maxn],fa[maxn],ans[maxn],dis[maxn];
void add(int u,int v,int val){
    G[cnt].to = v;
    G[cnt].next = head[u];
    G[cnt].val = val;
    head[u] = cnt++;
}
void init(){
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    memset(dis,0,sizeof(dis));
    rep(i,1,n+1) query[i].clear();
    rep(i,1,n+1) fa[i] = i;
    cnt = 0;
}
void dfs1(int u,int f){
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==f) continue;
        dis[v] = dis[u] + G[i].val;
        dfs1(v,u);
    }
}
int find(int x){
    if(x!=fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void dfs(int now){
    vis[now] = 1;
    for(int i=head[now];~i;i=G[i].next){
        int v = G[i].to;
        if(vis[v]) continue;
        dfs(v);
        fa[v] = now;
    }
    for(int i = 0;i<query[now].size();i++){
        Query node = query[now][i];
        int u = node.to; int id = node.id;
        if(vis[u]==2 || u==now){
            ans[id] = find(u);
        }
    }
    vis[now] = 2;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)){
        init();
        vector<pair<int,int> > ask;
        rep(i,0,m){
            int u,v,val;scanf("%d%d%d",&u,&v,&val);
            char s[10]; scanf("%s",s);
            add(u,v,val); add(v,u,val);
        }
        dfs1(1,-1);
        int t;scanf("%d",&t);
        rep(i,0,t){
            int u,v;
            scanf("%d%d",&u,&v);
            query[u].push_back(Query(v,i));
            query[v].push_back(Query(u,i));
            ask.push_back(make_pair(u,v));
        }
        dfs(1);
        rep(i,0,t){
            int x = ask[i].fi,y = ask[i].se;
            printf("%d\n",dis[x]-dis[ans[i]]+dis[y]-dis[ans[i]]);
        }
    }
    return 0;
}
