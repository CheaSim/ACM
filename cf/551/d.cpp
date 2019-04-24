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

const int maxn = 3e5+10;
int n;
int head[maxn],cnt;
struct node{
    int to,next;
}G[maxn<<1];
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
int sta[maxn]; // 0 means min , 1 means max
int son[maxn];
int dp[maxn];
void dfs(int u,int fa){
    if(son[u] == 0) {
        dp[u] = 1;
        return;
    }
    if(sta[u] == 1) dp[u] = INF;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        dfs(v,u);
        if(sta[u] == 0){
            dp[u] = dp[u] + dp[v];
        }else{
            dp[u] = min(dp[u],dp[v]);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    init();
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",sta+i);
    rep(i,0,n-1){
        int x; scanf("%d",&x);
        son[x] ++;
        addedge(x,i+2);
        addedge(i+2,x);
    }
    int t = 0;
    rep(i,1,n+1) if(son[i] == 0) t++;
    dfs(1,-1);
    printf("%d\n",t-dp[1]+1);
    return 0;
}
