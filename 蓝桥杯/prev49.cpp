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

const int maxn = 1e5+10;
struct node{
    int to,next;
}G[maxn<<1];
int head[maxn];
int cnt,n;
void init(){
    memset(head,-1,sizeof(head));
    cnt = 0;
}
void add_edge(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
int sta[maxn],top;
int vis[maxn];
vector<int> ans;
void dfs(int x,int fa){
    sta[top++] = x;
    for(int i=head[x];~i;i=G[i].next){
        int v = G[i].to;
        if(v == fa) continue;
        if(vis[v]){
            for(int j=top;sta[j] != v;j--){
                ans.pb(sta[j]);
            }
            continue;
        }
        vis[v] ++;
        dfs(v,x);
        vis[v] --;
    }
    top--;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int n;
    map<pair<int,int>,int> mx;
    bool flag = false;
    vector<int> aans;
    init();
    scanf("%d",&n);
    rep(i,0,n){
        int u,v; scanf("%d%d",&u,&v);
        add_edge(u,v); add_edge(v,u);
        mx[make_pair(u,v)]++;
        if(mx[make_pair(u,v)] == 2){
            flag = true;
            aans.pb(u); aans.pb(v);
        }
    }
    if(flag){
        sort(aans.begin(),aans.end());
        rep(i,0,2) cout<<aans[i]<<' ';
    }else{
        dfs(1,-1);
        sort(ans.begin(),ans.end());
        int len = ans.size();
        rep(i,0,len) cout<<ans[i]<<' ';
    }
    return 0;
}
