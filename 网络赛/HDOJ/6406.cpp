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
const int maxn = 2e5+100;
int n,m;
int a[maxn];
struct Segtree{
    int mmax[maxn<<2]={0},id[maxn<<2]={0},cur=0;
    void pushup(int rt){
        int x = id[rt<<1],y = id[rt<<1|1];
        id[rt] = a[x]>a[y]?x:y;
        mmax[rt] = max(mmax[rt<<1],mmax[rt<<1|1]);
    }
    void build(int l,int r,int rt){
        if(l==r){
            mmax[rt] = a[l];
            id[rt] = l;
            return;
        }
        int mid = l+r>>1;
        build(lson); build(rson);
        pushup(rt);
    }
    void query1(int val,int L,int R,int l,int r,int rt){
        if(l==r){
            if(mmax[rt]>val) cur = min(cur,id[rt]);
            return;
        }
        int mid = l+r>>1;
        if(L<=l && r<=R){
            if(mmax[rt<<1]>val) query1(val,L,R,lson);
            else if(mmax[rt<<1|1]>val) query1(val,L,R,rson);
            return;
        }
        if(L<=mid) query1(val,L,R,lson);
        if(mid<R) query1(val,L,R,rson);
    }
    void query2(int L,int R,int l,int r,int rt){
        if(L<=l && r<=R){
            if(mmax[rt]>a[cur]) cur = id[rt];
            return;
        }
        int mid = l+r>>1;
        if(L<=mid) query2(L,R,lson);
        if(mid<R) query2(L,R,rson);
    }
}st;
int dl[maxn],dr[maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        rep(i,1,n+1) scanf("%d",a+i);
        st.build(1,n,1);
        int mx = 0;
        memset(dr,0,sizeof(dr));
        memset(dl,0,sizeof(dl));
        rep(i,1,n+1){
            if(a[i]>mx){
                mx = a[i];
                dl[i] = dl[i-1]+1;
            }else{
                dl[i] = dl[i-1];
            }
        }
        per(i,1,n+1){
            st.cur = n+1;
            st.query1(a[i],i,n,1,n,1);
            if(st.cur>n) st.cur = 0;
            dr[i] = dr[st.cur]+1;
        }
        while(m--){
            int p,q;scanf("%d%d",&p,&q);
            int ans = 0; st.cur = 0;
            if(p>1) st.query2(1,p-1,1,n,1);
            ans += dl[st.cur];
            if(q > a[st.cur]) ans ++;
            if(q <= a[st.cur]) q = a[st.cur];
            st.cur = n+1;
            if(p<n) st.query1(q,p+1,n,1,n,1);
            if(st.cur<=n) ans += dr[st.cur];
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
