#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 2000000;
//head
int n,m;
const int maxn = 1e3+10;
struct node{
    int next,to,val;
}G[maxn<<1];
int head[maxn],val[maxn];
int cnt;
void addedge(int u,int v,int val){
    G[cnt].next = head[u];
    G[cnt].to = v;
    G[cnt].val = val;
    head[u] = cnt++;
}
void dfs(int u,int fa,int mid){
    if(G[head[u]].to == fa){
        val[u] = INF;
        return;
    }
    val[u] = 0;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        int w = G[i].val;
        if(v==fa) continue;
        dfs(v,u,mid);
        if(w > mid)  val[u]+=val[v];
        else val[u] += min(val[v],w);
    }
}
int solve(int l,int r){
    int ans = -1;int mid;
    while(l<=r){
        mid = l+r>>1;
        dfs(1,-1,mid);
        if(val[1]<=m){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
void init(){
    memset(head,-1,sizeof(head));
    cnt = 0;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) && (m||n)){
        init();
        rep(i,0,n-1){
            int u,v,val; scanf("%d%d%d",&u,&v,&val);
            addedge(u,v,val); addedge(v,u,val);
        }
        printf("%d\n",solve(1,m));
    }
    return 0;
}
