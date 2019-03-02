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
const int maxn = 4e4 + 10;
const ll mod = 1e9 + 7;
int T,n,m,cnt;
struct node{
    int to,next;
}G[maxn<<1];
int head[maxn],vis[maxn],sz[maxn],q[maxn],pre[maxn];
ll fac[maxn],f[maxn];
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    cnt = 0;
    rep(i,0,n+1){
        vis[i] = 0;
        head[i] = -1;
        sz[i] = 0;
        pre[i] = 0;
        f[i] = 1;
    }
}
ll pow3(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a % mod;
        b>>=1;
    }
    return res;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&T);
    fac[0] = 1;
    rep(i,1,maxn){
        fac[i] = fac[i-1]*i%mod;
    }
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        rep(i,0,m){
            int u,v;scanf("%d%d",&v,&u);
            add(u,v);vis[v] = 1;
        }
        rep(i,1,n+1) if(!vis[i]) add(0,i);
        memset(vis,0,sizeof(vis));
        vis[0] = 1;
        int l=0,r=0; q[0] = 0;vis[0] = 1;
        while(l<=r){
            int u = q[l++];
            for(int i = head[u];~i;i=G[i].next){
                int v = G[i].to;
                if(vis[v]) continue;
                pre[v] = u;
                vis[u] = 1;
                q[++r] = v;
            }
        }
        per(i,1,n+1){
            sz[q[i]]++;
            sz[pre[q[i]]] += sz[q[i]];
        }
        sz[0]++;
        ll res = 0;
        ll cnt = fac[n];
        rep(i,1,n+1) cnt = cnt*pow3(sz[i],mod-2)%mod;
        printf("%lld\n",cnt);
    }
    return 0;
}
