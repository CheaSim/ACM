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

const int maxn = 2e3+10;
vector<int> e[maxn];
// m is behind of the n
int fa[maxn];
int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int i,int j){
    int x = fa[i];
    int y = fa[j];
    if(x!=y) fa[x] = y;
}
int ind[maxn],use[maxn],vis[maxn];
char mx[maxn][maxn];
int n,m;
// flag means the 矛盾
bool flag;
int dp[maxn];
void dfs(int x,int dep){
    if(flag) return ;
    dp[x] = max(dp[x],dep);
    for(auto to:e[x]){
        if(vis[to]) {
            flag = true;
            return ;
        }
        if(dep+1>dp[to]){
            vis[to] = 1;
            dfs(to,dep+1);
            vis[to] = 0;
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,n){
        scanf("%s",mx+i);
    }
    rep(i,0,n+m) fa[i] = i;
    rep(i,0,n)
        rep(j,0,m)
            if(mx[i][j] == '=')
                Union(i,n+j);
    rep(i,0,n) rep(j,0,m){
        int x = Find(i); int y = Find(j+n);
        if(mx[i][j] == '<'){
            e[x].push_back(y);
            ind[y] ++;
            use[x] = 1;
        }else if(mx[i][j] == '>'){
            e[y].push_back(x);
            ind[x] ++;
            use[y] = 1;
        }else{
            use[x] = 1;
        }
    }
    bool fflag = false;
    rep(i,0,n+m){
        if(use[i] && ind[i] == 0){
            fflag = true;
            vis[i] = 1;
            dfs(i,1);
            vis[i] = 0;
        }
    }
    if(fflag == false || flag){
        puts("No");
    }else{
        puts("Yes");
        rep(i,0,n) printf("%d ",dp[Find(i)]);
        puts("");
        rep(i,n,m+n) printf("%d ",dp[Find(i)]);
    }
    return 0;
}
