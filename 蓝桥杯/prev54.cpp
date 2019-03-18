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
int fa[maxn*maxn];
int Find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = Find(fa[x]);
}
int Union(int x,int y){
    int i = Find(x);int j = Find(y);
    if(i!=j) fa[j] = i;
}
int n,m;
int k;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n*m+1) fa[i] = i;
    rep(i,0,k){
        int x,y; scanf("%d%d",&x,&y);
        Union(x,y);
    }
    int ans = 0;
    rep(i,1,n*m+1) if(fa[i] == i) ans++;
    printf("%d\n",ans);
    return 0;
}
