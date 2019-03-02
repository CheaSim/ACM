#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
#define pb push_back
//head
const int maxn = 1e5+10;
int n;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],cnt;
void add(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
ll a[maxn];
ll dp[maxn];
ll ans;
void dfs(int u,int fa){
    vector<ll> now;
    dp[u] = 1;
    a[u]--;
    if(G[head[u]].next == -1 && fa != -1){
        return;
    }
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        dfs(v,u);
        now.pb(dp[v]);
    }
    sort(now.begin(),now.end(),greater<ll>());
    for(int i=0;i<now.size();i++){
        if(a[u]){
            dp[u] += now[i]+1;
            a[u]--;
        }else break;
    }
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        if(a[u]){
            dp[u] += min(a[u],a[v])*2;
            a[u] -= min(a[v],a[u]);
        }else break;
    }
}
void init(){
    memset(head,-1,sizeof(head));
    cnt = 0;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    init();
    rep(i,1,n+1) scanf("%lld",a+i);
    rep(i,0,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    int root;scanf("%d",&root);
    a[root]++;
    dfs(root,-1);
    printf("%lld\n",dp[root]-1);
    return 0;
}
