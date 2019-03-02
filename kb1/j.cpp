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
const int maxn = 5e4+10;
int T,n,clk;
int on[maxn],in[maxn],ind[maxn],a[maxn<<2],lazy[maxn<<2];
vector<int> G[maxn];
void init(){
    clk = 0;
    memset(on,0,sizeof(on));
    memset(in,0,sizeof(in));
    memset(ind,0,sizeof(ind));
    memset(a,-1,sizeof(a));
    memset(lazy,-1,sizeof(lazy));
    rep(i,0,n+1) G[i].clear();
}
void dfs(int u,int fa){
    for(auto v:G[u]){
        if(v==fa) continue;
        in[v] = ++clk;
        dfs(v,u);
    }
    on[u] = clk;
}
void pushdown(int rt){
    if(lazy[rt]!=-1){
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        a[rt<<1] = a[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;
    }
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        lazy[rt] = val;
        a[rt] = val;
        return ;
    }
    pushdown(rt);
    int mid = l+r>>1;
    if(L<=mid) update(val,L,R,lson);
    if(mid<R) update(val,L,R,rson);
}
int query(int p,int l,int r,int rt){
    if(l==r && p==l) return a[rt];
    int mid = l+r>>1;
    pushdown(rt);
    if(p<=mid) return query(p,lson);
    else return query(p,rson);
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d",&n);
        init();
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            G[v].push_back(u);
            ind[u]++;
        }
        int root = 0;
        rep(i,1,n+1) if(ind[i]==0){
            root = i;
            break;
        }
        in[root] = ++clk;
        dfs(root,-1);
        int q;scanf("%d",&q);
        printf("Case #%d:\n",test_case);
        while(q--){
            char op[20];int x,y;
            scanf("%s",op);
            if(op[0]=='C'){
                scanf("%d",&x);
                printf("%d\n",query(in[x],1,n,1));
            }else{
                scanf("%d%d",&x,&y);
                update(y,in[x],on[x],1,n,1);
            }
        }
    }

    return 0;
}
