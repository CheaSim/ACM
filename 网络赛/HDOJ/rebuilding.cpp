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
const int maxn = 160;
int n,p,cnt;
struct node{
    int to,next;
}G[maxn<<1];
int head[maxn],dp[maxn][maxn];
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    rep(i,1,n+1){
        int son = 0;
        for(int j=head[i];~j;j=G[j].next){
            son++;
        }
        dp[i][1] = son;
        rep(j,2,p+1)
            dp[i][j] = INF;
    }
}
void dfs(int u,int fa){
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        dfs(v,u);
        per(j,2,p+1){
            rep(k,1,j){
                dp[u][j] = min(dp[u][j],dp[u][j-k]+dp[v][k]-2);
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("rebuild.in","r",stdin);
#endif
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&p);
    rep(i,0,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    init();
    dfs(1,-1);
    int ans = INF;
    rep(i,1,n+1){
        ans = min(ans,dp[i][p]);
    }
    printf("%d\n",ans); 

}
