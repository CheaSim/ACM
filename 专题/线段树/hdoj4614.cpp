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
const int maxn = 5e5 + 10;
int m,n,T;
int now,ed,st;
bool flag = 0;
int sum[maxn<<2],lazy[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void pushdown(int rt,int len){
    if(lazy[rt] == 0){
        lazy[rt<<1] = lazy[rt<<1|1] = 0;
        sum[rt<<1] = sum[rt<<1|1] = 0;
        lazy[rt] = -1;
    }
    if(lazy[rt] == 1){
        lazy[rt<<1] = lazy[rt<<1|1] = 1;
        sum[rt<<1] = len-len/2;
        sum[rt<<1|1] = len/2;
        lazy[rt] = -1;
    }
}
void build(int l,int r,int rt){
    lazy[rt] = -1;
    if(l==r){
        sum[rt] = 0;
        return ;
    }
    int mid = l+r>>1;
    build(lson);build(rson);
    pushup(rt);
}
void update(int p,int l,int r,int rt){
    if(now == 0) return;
    if(r-l+1 == sum[rt]) return;
    //cout<<l<<' '<<r<<' '<<sum[rt]<<"      ";
    if(sum[rt] == 0 && now >= r-l+1 && l>=p){
        sum[rt] = r-l+1;
        //cout<<l<<' '<<r<<"     "<<sum[rt]<<endl;
        now -= (r-l+1);
        lazy[rt] = 1;
        if(!flag) st = l,flag = 1,ed = r;
        else ed = r;
        return;
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    if(p <= mid) update(p,lson); 
    update(p,rson);
    pushup(rt);
}
void update(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        //cout<<l<<' '<<r<<' '<<sum[rt]<<"      ";
        now += sum[rt];
        sum[rt] = 0;
        lazy[rt] = 0;
        return;
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    if(L <= mid) update(L,R,lson);
    if(mid < R) update(L,R,rson);
    pushup(rt);
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        build(1,n,1);
        rep(i,0,m){
            int op,a,b;
            scanf("%d%d%d",&op,&a,&b);
            if(op==1){
                a++;
                now = b;st = ed = a; flag = 0;
                update(a,1,n,1);
                if(now==b){
                    puts("Can not put any one.");
                }else{
                    ed--;st--;
                    printf("%d %d\n",st,ed);
                }
            }else{
                now = 0;
                a++;b++;
                update(a,b,1,n,1);
                printf("%d\n",now);
            }
        }
        puts("");
    }

    return 0;
}
