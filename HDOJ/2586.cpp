#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 4e4+200;
const int maxm = 2e2+10;
int dis[maxn];
int n,m;
struct node{
    int next,to,val;
}G[maxn<<1];
int head[maxn];
int cnt;
vector<int> order;
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
    order.clear();
}
void add(int u,int v,int val){
    G[cnt].next = head[u];
    G[cnt].to = v;
    G[cnt].val = val;
    head[u] = cnt++;
}
void dfs(int u,int fa,int val){
    order.pb(u);
    dis[u] = val;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        dfs(v,u,val+G[i].val);
        order.pb(v);
    }
}
int find(int p1,int p2){
    int mmin = INF,res;
    if(p1>p2){
        int temp = p1;
        p1 = p2;
        p2 = temp;
    }
    rep(i,p1,p2+1){
        if(dis[order[i]] < mmin){
            mmin = dis[order[i]];
            res = i;
        }
    }
    return res+1;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        rep(i,0,n-1){
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            add(u,v,val); add(v,u,val);
        }
        dfs(1,1,0);
        int len = order.size();
        rep(i,0,m){
            int x,y; int p1=-1,p2=-1;
            scanf("%d%d",&x,&y);
            rep(j,0,len){
                if(p1==-1&&x==order[j]) p1 = j;
                if(p2==-1&&y==order[j]) p2 = j;
                if(p1!=-1 && p2!=-1) break;
            }
            int lca = find(p1,p2);
            cout<<dis[lca]<<' '<<dis[x]<<' '<<dis[y]<<endl;
            int ans = dis[x]-dis[lca]+dis[y]-dis[lca];
            printf("%d\n",ans);
        }

    }

    return 0;
}
