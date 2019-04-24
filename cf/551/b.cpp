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

int n,m,h;
const int maxn = 1e2+10;
int ma[maxn],mb[maxn];
int ans[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&h);
    rep(i,0,m) scanf("%d",ma+i);
    rep(i,0,n) scanf("%d",mb+i);
    rep(i,0,n){
        rep(j,0,m){
            int x; scanf("%d",&x);
            if(x){
                ans[i][j] = min(ma[j],mb[i]);
            }
        }
    }
    rep(i,0,n) rep(j,0,m) printf("%d%c",ans[i][j],j==m-1?'\n':' ');

    return 0;
}
