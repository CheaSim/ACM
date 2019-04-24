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

const int maxn = 2e5+10;
struct node{
    int next,to;
}G[maxn<<2];
int head[maxn];
int cnt;
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
int n,m;
map<pair<int,int>,int> mx;
int vis[maxn];
bool flag = false;
void dfs(int u,int fa,int f){
    vis[u] = f;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        mx[make_pair(u,v)] = f;
        mx[make_pair(v,u)] = f^1;
        if(vis[v] == -1){
        }else{
            if(vis[v]^vis[u]) continue;
            else {
                flag = true;
                continue;
            }
        }
        dfs(v,u,f^1);
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    init();
    scanf("%d%d",&n,&m);
    vector<pair<int,int> > ve;
    rep(i,0,m){
        int u,v; scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
        ve.push_back(make_pair(u,v));
    }
    memset(vis,-1,sizeof(vis));
    dfs(1,-1,1);
    if(flag) {
        puts("NO");
    }else{
        puts("YES");
        for(auto &x : ve){
            printf("%d",mx[x]);
        }
        puts("");
    }

    return 0;
}
