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
const int maxn = 1e3+10;
int vis[maxn];
int n;
struct node{
    int to,next;
}G[maxn<<1];
int head[maxn],cnt;
void init(){
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    cnt = 0;
}
void add(int u,int v){
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt++;
}
void dfs(int u,int fa,int dep){
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        vis[dep]++;
        dfs(v,u,dep+1);
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(~scanf("%d",&n)){
        init();
        rep(i,0,n-1){
            int u,v;scanf("%d%d",&u,&v);
            add(u,v); add(v,u);
        }
        dfs(1,-1,1);
        bool flag = true;
        rep(i,1,maxn){
            if(vis[i]==0) break;
            if(vis[i] >1 && vis[i+1] > 0){
                flag = false; break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }


    return 0;
}
