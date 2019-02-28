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
const int maxn = 30;
int dir[4][2] = {1,0, -1,0, 0,1, 0,-1};
char vis[maxn][maxn];
int res = 0;
int m,n;
void dfs(int x,int y){
    res++;
    rep(i,0,4){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx >= n || xx < 0 || yy >=m || yy < 0) continue;
        if(vis[xx][yy] == '.'){
            vis[xx][yy] = '#';
            dfs(xx,yy);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) && n && m){
        swap(n,m);
        res = 0;
        int stx,sty;
        rep(i,0,n){
            scanf("%s",vis[i]);
            rep(j,0,m){
                if(vis[i][j] == '@'){
                    stx = i; sty = j;
                }
            }
        }
        dfs(stx,sty);
        printf("%d\n",res);
    }

    return 0;
}
