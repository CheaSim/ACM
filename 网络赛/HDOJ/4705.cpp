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

const int maxn = 1e5+10;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],cnt;
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
ll ans = 0;
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
    ans = 0;
}
ll n;
ll sum[maxn],son[maxn];
ll tw[maxn];
void dfs(int u,int fa){
    sum[u] = 1;
    tw[u] = 0;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(fa == v) continue;
        dfs(v,u);
        ans += tw[v] * sum[u];
        ans += tw[u] * sum[v];
        sum[u] += sum[v];
        tw[u] += tw[v] + sum[v];
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(~scanf("%lld",&n)){
        init();
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v); add(v,u);
        }
        ll t = (ll)n*(n-1)*(n-2)/(ll)6;
        dfs(1,-1);
        printf("%lld\n",t-ans);
    }

    return 0;
}
