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
const int maxn = 4e5 + 10;
struct node{
    int to,next;
}G[maxn<<1];
int head[maxn];
ll f[maxn][4],g[maxn][4];
int n,cnt;
ll val[maxn];
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u,int fa){
    ll best[4][3] = {0}; ll temp[4][3] = {0}; ll last[4][3] = {0};
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        dfs(v,u);
        memset(temp,0,sizeof(temp));memset(best,0,sizeof(best));
        rep(x,0,4){
            temp[x][0] = f[v][x];
            temp[x][1] = g[v][x];
        }
        rep(x,0,4) rep(y,0,4-x) rep(p,0,3) rep(q,0,3-p)
            best[x+y][q+p] = max(best[x+y][p+q],last[x][p]+temp[y][q]);
        memcpy(last,best,sizeof(best));
    }
    rep(x,0,4) f[u][x] = max(f[u][x],best[x][0]);
    rep(x,1,4) rep(y,0,3) f[u][x] = max(f[u][x],val[u]+best[x-1][y]);
    rep(x,0,4) rep(y,0,2) g[u][x] = max(g[u][x],val[u]+best[x][y]);
}
int main(){
#ifdef LOCAL
    freopen("h.in","r",stdin);
#endif
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%lld",val+i);
    rep(i,0,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    dfs(1,-1);
    printf("%lld\n",f[1][3]);
    return 0;
}
