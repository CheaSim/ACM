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
//head -------------------------
const int maxn = 8e3+10;
int n;
int a[maxn<<2],lazy[maxn<<2],ans[maxn],id[maxn];
void pushup(int rt){
    a[rt] = max(a[rt<<1],a[rt<<1|1]);
}
void pushdown(int rt){
    if(lazy[rt]!=-1){
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        a[rt<<1] = a[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;
    }
}
void build(int l,int r,int rt){
    lazy[rt] = -1;
    if(l==r){
        a[rt] = -1;
        return;
    }
    int mid = l+r>>1;
    build(lson);build(rson);
    pushup(rt);
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        a[rt] = val;
        lazy[rt] = val;
        return ;
    }
    pushdown(rt);
    int mid = l+r>>1;
    if(L<=mid) update(val,L,R,lson);
    if(mid<R) update(val,L,R,rson);
    pushup(rt);
}
int query(int p,int l,int r,int rt){
    if(l==r && l==p){
        return a[rt];
    }
    int mid = l+r>>1;
    pushdown(rt);
    if(p<=mid) return query(p,lson);
    else if(mid<p) return query(p,rson);
    pushup(rt);
}
struct node{
    ll l,r;int x;
    node(){}
    node(ll x,ll y,int z):l(x),r(y),x(z){}
}ask[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(scanf("%d",&n)!=EOF){
        vector<ll> pp;
        build(1,n,1);
        memset(ans,0,sizeof(int)*(n+2));
        memset(id,0,sizeof(id));
        rep(i,1,n+1){
            ll l,r;int x;scanf("%lld%lld%d",&l,&r,&x);
            if(l>=r) continue;
            ask[i] = node(l,r,x);
            id[i] = x;
        }
        rep(i,0,n){
            pp.push_back(ask[i].l);pp.push_back(ask[i].r);
        }
        sort(pp.begin(),pp.end());
        pp.erase(unique(pp.begin(),pp.end()),pp.end());
        rep(i,1,n+1){
            ask[i].l = upper_bound(pp.begin(),pp.end(),ask[i].l)-pp.begin()+1;
            ask[i].r = upper_bound(pp.begin(),pp.end(),ask[i].r)-pp.begin();
        }
        rep(i,1,n+1){
            update(i,ask[i].l,ask[i].r,1,n,1);
        }
        int last = -1;
        rep(i,1,n+1){
            int pos = query(i,1,n,1);
            if(pos==-1) continue;
            if(id[pos]!=last){
                last = id[pos];
                ans[id[pos]]++;
            }
        }
        rep(i,0,8000+1){
            if(ans[i]==0) continue;
            printf("%d %d\n",i,ans[i]);
        }
        puts("");
    }
    return 0;
}
