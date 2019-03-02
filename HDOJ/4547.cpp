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
const int maxn = 1e5 + 10;
int cnt,n,m;
int head[maxn];
int fa[maxn];
struct node{
    int next,to;
}G[maxn<<1];
void addedge(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
struct ST{
    int tot;
    int first[maxn<<1],R[maxn<<1],order[maxn<<1],dp[maxn<<1][20],dis[maxn];
    void init(int root){
        tot = 0;
        memset(first,-1,sizeof(first));
        dfs(root,0,-1);
        ST_init(tot);
    }
    void ST_init(int n){
        rep(i,1,n+1) dp[i][0] = i;
        for(int j=1;(1<<j)<=n;j++){
            for(int i=1;i+(1<<j)-1<=n;i++){
                int a = dp[i][j-1],b = dp[i+(1<<(j-1))][j-1];
                dp[i][j] = R[a]<R[b]?a:b;
            }
        }
    }
    int LCA(int u,int v){
        int x = first[u],y = first[v];
        if(x>y) swap(x,y);
        int res = RMQ(x,y);
        return order[res];
    }
    int RMQ(int l,int r){
        int k = 0;
        while((1<<(k+1))<=r-l+1) k++;
        int a = dp[l][k],b = dp[r-(1<<k)+1][k];
        return R[a]<R[b]?a:b;
    }
    void dfs(int u,int deep,int f){
        R[++tot] = deep;
        dis[u] = deep;
        order[tot] = u;
        first[u] = tot;
        for(int i=head[u];~i;i=G[i].next){
            int v = G[i].to;
            if(v==f) continue;
            dfs(v,deep+1,u);
            order[++tot] = u;
            R[tot] = deep;
        }
    }
}st;
int find(int x){
    return x==fa[x]?x:fa[x] = find(fa[x]);
}
int ind[maxn];
char s[60];
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(ind,0,sizeof(ind));
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        map<string,int> mp;
        int tot = 0;
        rep(i,0,n-1){
            int u,v;
            scanf("%s",s);
            if(mp[s]==0) mp[s] = ++tot,u = tot;
            else u = mp[s];
            scanf("%s",s);
            if(mp[s]==0) mp[s] = ++tot,v = tot;
            else v = mp[s];
            addedge(v,u); ind[u]++;
        }
        int root = 0;
        rep(i,1,n+1) if(ind[i]==0){
            root = i;
            break;
        }
        st.init(root);
        rep(i,0,m){
            int u,v,ans;
            scanf("%s",s); u = mp[s];
            scanf("%s",s); v = mp[s];
            int rt = st.LCA(u,v);
            int x = st.dis[u] - st.dis[rt];
            int y = st.dis[v] - st.dis[rt];
            if(rt==u) ans = 1;
            else if(rt == v) ans = x;
            else ans = x+1;
            if(u==v) ans = 0;
            printf("%d\n",ans);
        }
    }

    return 0;
}
