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
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
struct node{
    int to,next;
}G[maxn<<1];
int head[maxn],pre[maxn],q[maxn],vis[maxn];
ll f[maxn],sz[maxn],fac[maxn];
int cnt,n,T;
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    cnt = 0;
    rep(i,0,n+1){
        head[i] = -1;
        q[i] = 0;
        f[i] = 1;
        vis[i] = 0;
        sz[i] = 0;
    }
}
ll pow3(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    fac[0] = 1;
    rep(i,1,maxn){
        fac[i] = fac[i-1]*i % mod;
    }
    while(T--){
        scanf("%d",&n);
        init();
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        int l = 0,r = 0;vis[1] = 1;q[0] = 1;
        while(l<=r){
            int u = q[l++];
            for(int i = head[u];~i;i=G[i].next){
                int v = G[i].to;
                if(vis[v]) continue;
                pre[v] = u;
                vis[v] = 1;
                q[++r] = v;
            }
        }
        per(i,1,n){
            sz[q[i]] ++;
            sz[pre[q[i]]] += sz[q[i]];
        }
        sz[1] ++;
        ll cnt = fac[n];
        rep(i,1,n+1) cnt = (cnt*pow3(sz[i],mod-2))%mod;
        ll ans = 0;
        ans = cnt*cnt %mod;f[1] = cnt;
        rep(i,1,n){
            ll cur = f[pre[q[i]]];
            cur = cur*sz[q[i]] %mod;
            cur = cur*pow3(n-sz[q[i]],mod-2)%mod;
            f[q[i]] = cur;
            ans = (ans + cur*cur%mod) % mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
