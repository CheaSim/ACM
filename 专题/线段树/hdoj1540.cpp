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
const int maxn = 5e4+10;
int sum[maxn<<2],vis[maxn],last[maxn];
int n,q;
void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt){
    if(l==r){
        sum[rt] = 1;
        return;
    }
    int mid = l+r>>1;
    build(lson); build(rson);
    pushup(rt);
}
void update(int val,int p,int l,int r,int rt){
    if(l==r && l==p){
        sum[rt] = val;
        return;
    }
    int mid = l+r>>1;
    if(p <= mid) update(val,p,lson);
    if(mid < p) update(val,p,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        return sum[rt];
    }
    int mid = l+r>>1;
    int ans = 0;
    if(L <= mid) ans += query(L,R,lson);
    if(mid < R) ans += query(L,R,rson);
    return ans;
}
int bit[maxn]={0};
int lowbit(int x){
    return x&-x;
}
void update(int x,int val){
    for(int i=x;i<=n+1;i+=lowbit(i)){
        bit[i] += val;
    }
}
int getsum(int x){
    int s=0;
    for(int i=x;i;i-=lowbit(i)){
        s += bit[i];
    }
    return s;
}
bool check(int l,int r){
    if(getsum(r)-getsum(l-1) == r-l+1) return true;
    return false;
}
int solve1(int l,int r,int rt){
    int st = rt;
    while(l<=r){
        int mid = l+r>>1;
        if(check(mid,r)) {r = mid-1;st = mid;}
        else l = mid+1;
    }
    //cout<<st<<' ';
    return st;
}
int solve2(int l,int r,int rt){
    int ed = rt;
    while(l<=r){
        int mid = l+r>>1;
        if(check(l,mid)) {l = mid+1; ed = mid;}
        else r = mid-1;
    }
    //cout<<ed<<' ';
    return ed;
}

int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d",&n,&q);
    build(1,n,1);
    rep(i,1,n+1) vis[i] = 1;
    rep(i,1,n+1) update(i,1);
    int top = 0;
    while(q--){
        char op[20];
        scanf("%s",op);
        if(op[0] == 'D'){
            int x; scanf("%d",&x);
            update(x,-1);
            last[top++] = x;
        }else if(op[0] == 'R'){
            int x =last[--top];
            update(x,1);
        }else{
            int x;scanf("%d",&x);
            if(getsum(x)-getsum(x-1)==0){
                puts("0");
                continue;
            }
            printf("%d\n",solve2(x,n,x)-solve1(1,x,x)+1);
        }
    }

    return 0;
}
