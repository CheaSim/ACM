#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 2e4+100;
int n;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],cnt;
void addedge(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
int sum[maxn],mmax[maxn];
void dfs(int u,int fa){
    sum[u] = 1;
    mmax[u] = 1;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        dfs(v,u);
        sum[u] += sum[v];
        mmax[u] = max(mmax[u],sum[v]);
    }
    mmax[u] = max(mmax[u],n-sum[u]);
}
void init(){
    memset(head,-1,sizeof(head));
    memset(mmax,0,sizeof(mmax));
    cnt = 0;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            addedge(u,v); addedge(v,u);
        }
        dfs(1,0);
        int ans = INF;
        rep(i,1,n+1) ans = min(ans,mmax[i]);
        int res = 0;
        rep(i,1,n+1){
            if(mmax[i] == ans) {
                res = i;
                break;
            }
        }
        printf("%d %d\n",res,ans);
    }

    return 0;
}
