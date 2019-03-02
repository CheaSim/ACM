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
int n,now,maxl,maxr,flag;
const int maxn = 5e4+20;
int sum[maxn<<2],lazy[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void pushdown(int rt,int len){
    if(lazy[rt] != -1){
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = lazy[rt]*(len-len/2);
        sum[rt<<1|1] = lazy[rt]*(len/2);
        lazy[rt] = -1;
    }
}
void build(int l,int r,int rt){
    lazy[rt] = -1;
    if(l==r){
        sum[rt] = 0;
        return;
    }
    int mid = l+r>>1;
    build(lson); build(rson);
    pushup(rt);
}
void update1(int p,int l,int r,int rt){
    if(now == 0) return;
    int len = r-l+1;
    if(sum[rt] == len) return;
    if(l>=p && sum[rt] == 0 && len <= now){
        now -= len;
        sum[rt] = len;
        lazy[rt] = 1;
        if(flag == 0)
        maxl = l,flag = 1; 
        maxr = max(maxr,r);
        return;
    }
    pushdown(rt,len);
    int mid = l+r>>1;
    if(p<=mid) update1(p,lson);
    update1(p,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        lazy[rt] = 0;
        int temp = sum[rt];
        sum[rt] = 0;
        return temp;
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    int ans = 0;
    if(L<=mid) ans += query(L,R,lson);
    if(mid<R) ans += query(L,R,rson);
    pushup(rt);
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("l.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int m;scanf("%d%d",&n,&m);
        build(1,n,1);
        rep(i,0,m){
            int op,x,y;scanf("%d%d%d",&op,&x,&y);
            x++;
            if(op==1){
                now = y;
                maxl = x;maxr = x;flag = 0;
                update1(x,1,n,1);
                if(now == y)
                    puts("Can not put any one.");
                else
                    printf("%d %d\n",maxl-1,maxr-1);
            }else{
                y++;
                printf("%d\n",query(x,y,1,n,1));
            }
        }
        puts("");
    }

    return 0;
}
