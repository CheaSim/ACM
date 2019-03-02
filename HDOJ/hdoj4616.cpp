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
const int maxn = 5e4 + 10;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],trap[maxn],val[maxn],dp[maxn][4][2];
int cnt,T,n,c,ans;
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    cnt = 0;
    memset(head,-1,sizeof(int)*(n+2));
    memset(trap,0,sizeof(int)*(n+2));
    memset(dp,0,sizeof(dp));
    ans = 0;
}
void dfs1(int u,int fa){
    dp[u][trap[u]][trap[u]] = val[u];
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(fa == v) continue;
        dfs1(v,u);
        for(int j=0;j<=c;j++){
            for(int k=0;k+j<=c;k++){
                ans = max(ans,dp[u][j][1]+dp[v][k][1]);
                if(j) ans = max(ans,dp[u][j][1]+dp[v][k][0]);
                if(k) ans = max(ans,dp[u][j][0]+dp[v][k][1]);
                if(j+k<c) ans = max(ans,dp[u][j][0]+dp[v][k][0]);
            }
        }
        for(int j=0;j+trap[u]<=c;j++){
            dp[u][j+trap[u]][0] = max(dp[u][j+trap[u]][0],dp[v][j][0]+val[u]);
            if(j) dp[u][j+trap[u]][1] = max(dp[u][j+trap[u]][1],dp[v][j][1]+val[u]);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&c);
        init();
        rep(i,0,n) scanf("%d%d",&val[i],&trap[i]);
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        dfs1(0,-1);
        printf("%d\n",ans);
    }
    return 0;
}
