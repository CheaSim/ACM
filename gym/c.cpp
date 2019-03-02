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

const int maxn = 1e5+10;
struct node{
    int next,to;
}G[maxn<<2];
int head[maxn],cnt;
void init(){
    memset(head,-1,sizeof(head));
    cnt = 0;
}
void add(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
struct nn{
    int p,q;
    int id;
}a[maxn];
bool cmp1(nn x,nn y){
    return x.p>y.p;
}
bool cmp2(nn x,nn y){
    return x.q>y.q;
}
int vis[maxn];
int n;
int ans;
void dfs(int u){
    if(vis[u]) return;
    ans++;
    vis[u] = 1;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        dfs(v);
    }
}
int res[maxn];
int main(){
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    init();
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d%d",&a[i].p,&a[i].q);
        a[i].id = i+1;
    }
    sort(a,a+n,cmp1);
    rep(i,0,n-1) add(a[i].id,a[i+1].id);
    sort(a,a+n,cmp2);
    rep(i,0,n-1) add(a[i].id,a[i+1].id);
    
    per(i,0,n){
        dfs(a[i].id);
        res[a[i].id] = ans-1;
    }
    rep(i,1,n+1){
        printf("%d\n",res[i]);
    }

    return 0;
}
