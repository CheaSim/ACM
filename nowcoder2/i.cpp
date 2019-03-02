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
const int maxn = 1e5 + 10;
int col[maxn],row[maxn];
int main(){
#ifdef LOCAL
    freopen("i.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    int ans = 2*n;
    if(n%2) ans--;
    rep(i,0,m){
        int x,y;scanf("%d%d",&x,&y);
        row[x] = 1;col[y]=1;
    }
    rep(i,1,n+1){
        if(row[i]) ans--;
        if(col[i]) ans--;
    }
    if(n%2 && row[(n+1)/2]==1 && col[(n+1)/2]) ans++;
    printf("%d\n",ans);
    return 0;
}
