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

int n,m,c,cnt;
const int maxn = 1e4+10;
struct node{
    int next,to,val;
}G[maxn<<2];
int head[maxn],fa[maxn],vis[maxn],ans[maxn*100],dis[maxn];
void add(int u,int v,int val){
    G[cnt].to = v;
    G[cnt].next = head[u];
    G[cnt].val = val;
    head[u] = cnt++;
}
struct Query{
    int to,id;
    Query(){}
    Query(int a,int b){
        to = a;
        id = b;
    }
};
vector<Query> query[maxn];
int find(int x){
    if(x!=fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void dfs(int now){
    vis[now] = 1;
    for(int i=head[now];~i;i=G[i].next){
        int v = G[i].to;
        if(vis[v]) continue;
        dis[v] = dis[now] + G[i].val;
        dfs(v);
        fa[v] = now;
    }
    int len = query[now].size();
    for(int i = 0;i<len;i++){
        int u = query[now][i].to; int id = query[now][i].id;
        if(vis[u]==2 || u==now){
            ans[id] = find(u);
        }
    }
    vis[now] = 2;
}
void init(){
    memset(head,-1,sizeof(int)*(n+2));
    memset(vis,0,sizeof(int)*(n+1));
    rep(i,1,n+1) query[i].clear();
    rep(i,1,n+1) fa[i] = i;
    cnt = 0;
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
int ask[1000001][2];
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
            query[u].push_back(Query(v,i));
            query[v].push_back(Query(u,i));
            ask[i][0] = u;ask[i][1] = v;
        }
        rep(i,1,n+1) fa[i] = i;
        dfs(0);
        rep(i,0,c){
            if(ans[i]==0){
                puts("Not connected");
                continue;
            }
            int x = ask[i][0], y = ask[i][1];
            printf("%d\n",dis[x]+dis[y]-2*dis[ans[i]]);
        }
    }

    return 0;
}
