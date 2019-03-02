#include<cstdio>
#include<vector>
#include<iostream>
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
int T,n,cnt;
const int maxn = 1e4+10;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],fa[maxn],vis[maxn],ans[10];
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(fa,0,sizeof(fa));
    memset(vis,0,sizeof(vis));
    rep(i,1,n+1) fa[i] = i;
}
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
int find(int x){
    if(fa[x]!=x) fa[x] = find(fa[x]);
    return fa[x];
}
struct Query{
    int to,id;
    Query(){}
    Query(int _to,int _id){
        to = _to;
        id = _id;
    }
};
vector<Query> query[maxn];
void dfs(int now){
    int u,v;
    vis[now] = 1;
    for(int i=head[now];~i;i=G[i].next){
        v = G[i].to;
        if(vis[v]) continue;
        dfs(v);
        fa[v] = now;
    }
    for(int i = 0;i<query[now].size();i++){
        Query node = query[now][i];
        u = node.to; int id = node.id;
        if(vis[u] == 2){
            ans[id] = find(u);
        }
    }
    vis[now] = 2;
}
int root[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(root,0,sizeof(root));
        memset(ans,0,sizeof(ans));
        rep(i,1,n+1) query[i].clear();
        init();
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v);
            root[v] = 1;
        }
        int u,v;scanf("%d%d",&u,&v);
        query[v].push_back(Query(u,1));
        query[u].push_back(Query(v,1));
        int real = 1;
        rep(i,1,n+1){
            if(root[i]==0){
                real = i;
                break;
            }
        }
        dfs(real);
        printf("%d\n",ans[1]);
    }

    return 0;
}
