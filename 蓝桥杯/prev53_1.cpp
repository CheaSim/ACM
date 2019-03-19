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

int n,m;
const int maxn = 1e2+10;
int g[maxn][maxn];
vector<int> st[maxn];
int ans = INF;
int vis[maxn];
void dfs(int x,int now){
    if(now >= ans) return;
    if(x>n){
        ans = min(now,ans);
        return;
    }
    rep(i,0,now){
        int t = 0;
        int len = st[i].size();
        rep(j,0,len){
            if(g[x][st[i][j]] == 0) t++;
        }
        if(t==len){
            st[i].push_back(x);
            dfs(x+1,now);
            st[i].pop_back();
        }
    }
    st[now].push_back(x);
    dfs(x+1,now+1);
    st[now].pop_back();
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,m){
        int x,y; scanf("%d%d",&x,&y);
        g[x][y] = g[y][x] = 1;
    }
    dfs(1,0);
    printf("%d\n",ans);



    return 0;
}
