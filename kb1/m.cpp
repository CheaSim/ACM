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
//head ----------------------------------------
const int maxn = 1e6+20;
int T,n,m;
struct sgt{
    int maxlen[maxn<<2];
    int ll[maxn<<2],rr[maxn<<2],mm[maxn<<2];
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
}all,ns;
char op[20];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    rep(test_case,1,T+1){
        printf("Case %d:\n",test_case);
        scanf("%d%d",&n,&m);
        //all.build(1,n,1); ns.build(1,n,1);
        all.init(); ns.init();
        while(m--){
            scanf("%s",op);
            if(op[0]=='D'){
                int x;scanf("%d",&x);
                int ans = all.query(x,1,n,1);
                if(ans){
                    all.update(0,ans,ans+x-1,1,n,1);
                    printf("%d,let's fly\n",ans);
                }else{
                    puts("fly with yourself");
                }
            }else if(op[0]=='N'){
                int x;scanf("%d",&x);
                int ans = all.query(x,1,n,1);
                if(!ans) ans = ns.query(x,1,n,1);
                if(ans){
                    all.update(0,ans,ans+x-1,1,n,1);
                    ns.update(0,ans,ans+x-1,1,n,1);
                    printf("%d,don't put my gezi\n",ans);
                }else{
                    puts("wait for me");
                }
            }else{
                int x,y;scanf("%d%d",&x,&y);
                all.update(1,x,y,1,n,1);
                ns.update(1,x,y,1,n,1);
                puts("I am the hope of chinese chengxuyuan!!");
            }
        }
    }
    
    return 0;
}
