#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
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
const int maxn = 2e5 + 20;
int vis[maxn],lx[maxn],rx[maxn],lazy[maxn<<2],mmax[maxn<<2];
int T,n;
void pushdown(int rt){
    if(lazy[rt]){
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        mmax[rt<<1] = mmax[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int l,int r,int rt){
    lazy[rt] = 0;
    if(l==r){
        mmax[rt] = 0;
        return ;
    }
    int mid = l+r>>1;
    build(lson); build(rson);
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        lazy[rt] = val;
        mmax[rt] = val;
        return ;
    }
    pushdown(rt);
    int mid = l+r>>1;
    if(L <= mid) update(val,L,R,lson);
    if(mid < R) update(val,L,R,rson);
}
int query(int p,int l,int r,int rt){
    if(l==r && l==p){
        return mmax[rt];
    }
    int mid = l+r>>1;
    pushdown(rt);
    if(p <= mid) return query(p,lson);
    if(mid < p) return query(p,rson);
}
int main(){
#ifdef LOCAL
    freopen("d.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        vector<int>x;
        rep(i,1,n+1){
            int l,r;scanf("%d%d",lx+i,rx+i);
            x.push_back(lx[i]);x.push_back(rx[i]);
        }
        sort(x.begin(),x.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        rep(i,1,n+1){
            lx[i] = lower_bound(x.begin(),x.end(),lx[i])-x.begin()+1;
            rx[i] = lower_bound(x.begin(),x.end(),rx[i])-x.begin()+1;
        }
        int len = x.size();
        build(1,len,1);
        rep(i,1,n+1){
            update(i,lx[i],rx[i],1,len,1);
        }
        memset(vis,0,sizeof(vis));
        int ans = 0;
        rep(i,1,len+1){
            int x = query(i,1,len,1);
            if(vis[x] == 0){
                ans ++;
                vis[x] = 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
