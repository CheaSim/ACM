#include<cstring>
#include<stdio.h>
#include<cmath>
#include<algorithm>
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
const int maxn = 1e5 + 10;
int sum[maxn<<2],a[maxn],lazy[maxn<<2];
int n,q,T;
void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int len){
    if(lazy[rt]){
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = lazy[rt]*(len-len/2);
        sum[rt<<1|1] = lazy[rt]*(len/2);
        lazy[rt] = 0;
    }
}
void build(int l,int r,int rt){
    lazy[rt] = 0;
    if(l==r){
        sum[rt] = 1;
        return;
    }
    int mid = l+r>>1;
    build(lson);build(rson);
    pushup(rt);
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        lazy[rt] = val;
        sum[rt] = val*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    if(L <= mid) update(val,L,R,lson);
    if(mid < R) update(val,L,R,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    ll ans = 0;
    if(L <= mid) ans += query(L,R,lson);
    if(mid < R) ans += query(L,R,rson);
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("e.in","r",stdin);
#endif
    scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d%d",&n,&q);
        build(1,n,1);
        rep(i,0,q){
            int l,r,val; scanf("%d%d%d",&l,&r,&val);
            update(val,l,r,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",test_case,query(1,n,1,n,1));
    }
    return 0;
}
