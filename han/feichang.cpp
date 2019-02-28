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
int vis[maxn][maxn][maxn];
int a,b,c;
void dfs(int x,int y,int z,int d){
    if(x<0 || y<0 || z<0) return;
    if(x>a || y>b || z>c) return;
    if(vis[x][y][z] < d) return;
    vis[x][y][z] = d;
    
    // 倒给X
    dfs(x+y,0,z,d+1);
    dfs(x+z,y,0,d+1);

    // 倒给Y
    dfs(x , b , z - (b-y),d+1);
    dfs(x , y+z, 0,d+1);

    dfs(x - (b-y) , b, z,d+1);
    dfs(0 , x+y, z,d+1);

    // 倒给Z
    dfs(0 , y , z+x,d+1);
    dfs(x - (c-z) , y , c,d+1);

    dfs(x , y-(c-z),c,d+1);
    dfs(x , 0 , z+y,d+1);
}


int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>a>>b>>c && a && b && c){
        rep(i,0,maxn) rep(j,0,maxn) rep(k,0,maxn) vis[i][j][k] = INF;
        if(b<c) swap(b,c);
        dfs(a,0,0,0);
        if(a%2==0){
            if(vis[a/2][a/2][0] != INF){
                printf("%d\n",vis[a/2][a/2][0]);
            }else{
                printf("NO\n");
            }
        }else{
            puts("NO");
        }
    }


    return 0;
}
