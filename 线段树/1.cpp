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
int a[maxn<<2],lazy[maxn<<2],ans[maxn<<2],id[maxn<<2],vis[maxn<<2];
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
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        a[rt] = val;
        lazy[rt] = val;
        return;
    }
    pushdown(rt);
    int mid = l+r>>1;
    if(L<=mid) update(val,L,R,lson);
    if(mid<R) update(val,L,R,rson);
}
void query(int l,int r,int rt){
    if(l==r){
        vis[l] = a[rt];
        return;
    }
    int mid = l+r>>1;
    pushdown(rt);
    query(lson);
    query(rson);
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(scanf("%d",&n)!=EOF){
        build(1,8000,1);
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        memset(id,0,sizeof(id));
        rep(i,1,n+1){
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            if(l>=r) continue;
            update(x,l+1,r,1,8000,1);
        }
        query(1,8000,1);
        int last = -1;
        //int i = 1;
        rep(i,1,maxn){
            while(vis[i]==-1) i++,last=-1;
            if(i>=maxn) break;
            if(vis[i] != last){
                last = vis[i];
                ans[vis[i]]++;
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
