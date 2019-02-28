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

const int maxn = 1e2+10;
int n,m;
char vis[maxn][maxn];
int dir[8][2] = {1,0, -1,0, 0,1, 0,-1, 1,1 , 1,-1, -1,1,-1,-1};
void dfs(int x,int y){
    rep(i,0,8){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if(vis[xx][yy] == '@'){
            vis[xx][yy] = '*';
            dfs(xx,yy);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(cin>>n>>m && n && m){
        rep(i,0,n){
            scanf("%s",vis[i]);
        }
        int ans = 0;
        rep(i,0,n){
            rep(j,0,m){
                if(vis[i][j] == '@'){
                    vis[i][j] = '*';
                    dfs(i,j);
                    ans ++;
                }
            }
        }
        printf("%d\n",ans);
    }



    return 0;
}
