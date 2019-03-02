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
const int maxn = 5e3 + 10;
int n,k,D,tot;
const ll mod = 1e9 + 7;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],vis[maxn],cnt[maxn],dis[maxn][maxn];
void add(int u,int v){
    G[tot].to = v;
    G[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int u,int fa,int rt){
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        dis[v][rt] = dis[u][rt]+1;
        dfs(v,u,rt);
    }
}
ll solve(int d){
    queue<int>q;
    rep(i,1,n+1) cnt[i] = k;
    ll ans = 1;
    q.push(1);
    memset(vis,0,sizeof(vis));vis[1] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        ll res = 0;
        rep(v,1,n+1) if(v!=u) cnt[v] -= (dis[u][v]<d);
        if(cnt[u] <= 0) return 0;
        ans = ans*cnt[u]%mod;
        for(int i=head[u];~i;i=G[i].next){
            int v = G[i].to;
            if(dis[1][u]+1 == dis[1][v]){
                q.push(v);
            }
        }
    }
    return ans;
}
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;   c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}
int main(){
#ifdef LOCAL
    freopen("j.in","r",stdin);
#endif
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&k,&D);
    rep(i,0,n-1){
        int u,v; u = read(); v = read();
        add(u,v); add(v,u);
    }
    rep(i,1,n+1) dfs(i,-1,i);
    printf("%lld\n",(solve(D)-solve(D+1)+mod)%mod);
    return 0;
}
