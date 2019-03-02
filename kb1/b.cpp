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
const int maxn = 2e5 + 10;
int n,m;
int mmax[maxn<<2],a[maxn];
void pushup(int rt){
    mmax[rt] = max(mmax[rt<<1],mmax[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        mmax[rt] = a[l];
        return;
    }
    int mid = l+r>>1;
    build(lson);build(rson);
    pushup(rt);
}
void update(int val,int p,int l,int r,int rt){
    if(l==r && l==p){
        mmax[rt] = val;
        return;
    }
    int mid = l+r>>1;
    if(p <= mid) update(val,p,lson);
    if(mid < p) update(val,p,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R) return mmax[rt];
    int mid = l+r>>1;
    int ans = 0;
    if(L <= mid) ans = max(ans,query(L,R,lson));
    if(mid < R) ans = max(ans,query(L,R,rson));
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("b.in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)){
        rep(i,1,n+1) scanf("%d",a+i);
        build(1,n,1);
        rep(i,0,m){
            char op[20];int x,y;
            scanf("%s%d%d",op,&x,&y);
            if(op[0] == 'Q'){
                printf("%d\n",query(x,y,1,n,1));
            }else{
                update(y,x,1,n,1);
            }
        }
    }
    return 0;
}
