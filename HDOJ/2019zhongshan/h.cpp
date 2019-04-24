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
int a,b,c;
const int maxn = 1e2+10;
int front[maxn][maxn];
int side[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    
    while(~scanf("%d%d%d",&a,&b,&c)){
    rep(i,0,a) rep(j,0,b) scanf("%d",&front[i][j]);
    rep(i,0,b) rep(j,0,c) scanf("%d",&side[i][j]);
    int ans = 0;
    rep(i,0,c) rep(j,0,a){
        int x; scanf("%d",&x);
        if(x){
            rep(k,0,b) if((front[j][k]&side[k][i]) == 1) ans++;
        }
    }
    printf("%d\n",ans);}

    return 0;
}
