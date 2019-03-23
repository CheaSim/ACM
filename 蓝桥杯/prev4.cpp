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

const int maxn = 20;
int mx[maxn][maxn];
int dir[4][2] = {1,0, -1,0, 0,-1, 0,1};
int half = 0;
int n,m;
int vis[maxn][maxn];
int ans = INF;
void dfs(int x,int y,int now,int cnt){
    if(now > half) return;
    if(now == half){
        ans = min(ans,cnt);
        return;
    }
    if(x == n) return;
    rep(i,1,m+1){
        dfs(x+1,i,now+ss[x][i-1],cnt+i);
    }
}
int ss[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&m,&n);
    int sum = 0;
    rep(i,0,n) rep(j,0,m){
        scanf("%d",mx[i]+j);
        sum += mx[i][j];
    }
    rep(i,0,n) rep(j,1,m){
        ss[i][j] += ss[i][j-1] + mx[i][j];
    }
    half = sum/2;
    bool flag = false;
    if(sum%2==0) flag = true;
    dfs(0,0,mx[0][0],1);
    if(ans != INF && flag)
        printf("%d\n",ans);
    else puts("0");
    return 0;
}
