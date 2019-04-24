#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 1e5+10;
int head[mxan],cnt,n,m,fa[maxn];
struct node{
    int next,to,val;
}G[maxn<<1];
void init(){
    cnt = 0; memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int val){
    G[cnt].next = head[u];
    G[cnt].to = v;
    G[cnt].val = val;
    head[u] = cnt++;
}
struct ST{
    int tot;
    int first[maxn<<1],R[maxn<<1],order[maxn<<1],dp[maxn<<1][20],dis[maxn];
    void init(int root){
        tot = 0;
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
struct sgt{
    int maxlen[maxn<<2];
    int mmax[maxn<<2], mmin[maxn<<2];
    int lazy[maxn<<2];
    void build(int l,int r,int rt){
        lazy[rt] = -1;
        if(l==r){
            ll[rt] = rr[rt] = 0;
            mm[rt] = 1;
            return;
        }
        int mid = l+r>>1;
        build(lson); build(rson);
    }
    void init(){
        lazy[1] = 1;
    }
    void pushup(int l,int r,int rt){
        if(lazy[rt]>=0){
            maxlen[rt] = ll[rt] = rr[rt] = mm[rt] = (lazy[rt]?(r-l+1):0);
        }else{
            int lc = rt<<1,rc = rt<<1|1,mid = l+r>>1;
            ll[rt] = ll[lc];
            if(ll[lc]==(mid-l+1)) ll[rt] += ll[rc];
            mm[rt] = rr[lc] + ll[rc];
            rr[rt] = rr[rc];
            if(rr[rc] == r-mid) rr[rt] += rr[lc];
            maxlen[rt] = max(maxlen[lc],max(maxlen[rc],mm[rt]));
        }
    }
    void pushdown(int rt){
        if(lazy[rt]>=0){
            int lc=rt<<1,rc=rt<<1|1;
            lazy[lc] = lazy[rc] = lazy[rt];
            lazy[rt] = -1;
        }
    }
    int query(int val,int l,int r,int rt){
        pushup(l,r,rt);
        //cout<<l<<' '<<r<<' '<<"         ";
        int lc = rt<<1,rc = rt<<1|1,mid = l+r>>1;
        if(val>maxlen[rt]) return 0;
        if(ll[rt] >= val) return l;
        pushdown(rt);
        pushup(rson);
        int temp = query(val,lson);
        if(temp) return temp;
        if(mm[rt] >= val) return mid-rr[lc]+1;
        return query(val,rson);
    }
    void update(int val,int L,int R,int l,int r,int rt){
        if(L<=l && r<=R){
            lazy[rt] = val;
            pushup(l,r,rt);
            return;
        }
        pushdown(rt);
        int mid = l+r>>1;
        if(L<=mid) update(val,L,R,lson);
        else pushup(lson);
        if(mid<R) update(val,L,R,rson);
        else pushup(rson);
        pushup(l,r,rt);
    }
}sgt;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,n-1){
        int u,v; scanf("%d%d",&u,&v);
        addedge(u,v,val); addedge(v,u,val);
    }
    st.init();

    return 0;
}
