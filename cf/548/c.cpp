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
const ll mod = 1e9+7;
const int maxn = 1e5+10;
int cnt,n,k;
int head[maxn];
struct node{
    int next,to,val;
}G[maxn<<1];
void addedge(int u,int v,int val){
    G[cnt].next = head[u];
    G[cnt].to = v;
    G[cnt].val = val;
    head[u] = cnt++;
}
void init(){
    memset(head,-1,sizeof(head));
    cnt = 0;
}
int vis[maxn];
int t = 0;
void dfs(int u,int fa){
    t ++;
    vis[u] = 1;
    for(int i = head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        if(vis[v]) continue;
        if(G[i].val == 0)dfs(v,u);
    }
}
ll pow3(ll a,ll b){
    ll res = 1;
    ll x = a;
    while(b){
        if(b&1) res  = res * x % mod;
        b >>= 1;
        x = x*x%mod;
    }
    return res;
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    init();
    scanf("%d%d",&n,&k);
    rep(i,0,n-1){
        int u,v,val; scanf("%d%d%d",&u,&v,&val);
        addedge(u,v,val); addedge(v,u,val);
    }
    ll ans = pow3(n,k);
    ll last = 0;
    rep(i,1,n+1){
        if(vis[i]==0) dfs(i,-1);
        ll temp = t - last;
        last = t;
        ans = (ans + mod - pow3(temp,k)) % mod;
    }
    printf("%lld\n",ans);
    return 0;
}
