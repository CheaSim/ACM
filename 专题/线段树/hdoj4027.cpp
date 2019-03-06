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
const int maxn = 1e5 + 10;
int n,q;
ll sum[maxn<<2],mmax[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    mmax[rt] = max(mmax[rt<<1],mmax[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        ll x;scanf("%lld",&x);
        mmax[rt] = sum[rt] = x;
        return;
    }
    int mid = l+r>>1;
    build(lson);build(rson);
    pushup(rt);
}
void update(int L,int R,int l,int r,int rt){
    if(mmax[rt]==1) return;
    if(l==r){
        mmax[rt] = sqrt(mmax[rt]);
        sum[rt] = sqrt(sum[rt]);
        return;
    }
    int mid = l+r>>1;
    if(L<=mid) update(L,R,lson);
    if(mid<R) update(L,R,rson);
    pushup(rt);
}
ll query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R) return sum[rt];
    int mid = l+r>>1;
    ll ans = 0;
    if(L<=mid)  ans += query(L,R,lson);
    if(mid<R) ans += query(L,R,rson);
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int test_case = 1;
    while(~scanf("%d",&n)){
        build(1,n,1);
        scanf("%d",&q);
        printf("Case #%d:\n",test_case++);
        while(q--){
            int l,r,op;scanf("%d%d%d",&op,&l,&r);
            if(l>r){
                int temp = l;
                l = r;
                r = temp;
            }
            if(op==0){
                update(l,r,1,n,1);
            }else{
                printf("%lld\n",query(l,r,1,n,1));
            }
        }
        puts("");
    }
    return 0;
}
