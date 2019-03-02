#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 2e5 + 10;
int a[maxn],last[maxn],nxt[maxn],vis[maxn],pre[maxn],bit[maxn];
int n,q;
struct node{
    int l,r,id;
    bool operator<(const node& x){
        return l < x.l;
    }
}ask[maxn];
int lowbit(int x){return x&-x;}
void update(int x,int val){
    for(int i=x;i<=n*2;i+=lowbit(i)){
        bit[i] += val;
    }
}
int query(int x){
    int s = 0;
    for(int i=x;i;i-=lowbit(i)){
        s += bit[i];
    }
    return s;
}
int query(int l,int r){
    return query(r) - query(l-1);
}
void init(){
    memset(vis,0,sizeof(vis));
    memset(last,-1,sizeof(last));
    memset(nxt,-1,sizeof(nxt));
    memset(bit,0,sizeof(bit));
}
int main(){
#ifdef LOCAL
    freopen("j.in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&q)){
        init();
        rep(i,1,n+1) scanf("%d",&a[i]),a[i+n] = a[i];
        rep(i,1,n+n+1){
            if(!vis[a[i]]){
                pre[i] = pre[i-1] + 1;
                vis[a[i]] = 1;
            }else{
                pre[i] = pre[i-1];
            }
            if(~last[a[i]]) nxt[last[a[i]]] = i;
            last[a[i]] = i;
        }
        rep(i,0,q){
            int l,r;scanf("%d%d",&l,&r);
            int temp = l;l = r;r = temp + n;
            ask[i].l = l;ask[i].r = r;ask[i].id = i;
        }
        sort(ask,ask+q);
        int nowl = 1;
        int ans[maxn];
        rep(i,0,q){
            while(nowl < ask[i].l){
                if(~nxt[nowl])update(nxt[nowl],1);
                nowl++;
            }
            ans[ask[i].id] = pre[ask[i].r] - pre[ask[i].l-1] +query(ask[i].l,ask[i].r);
        }
        rep(i,0,q) printf("%d\n",ans[i]);
    }
    return 0;
}
