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

int n,m,k;
const int maxn = 110;
int p[maxn];
int s[maxn];
int c[maxn];
int sts[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n+1) scanf("%d",p+i);
    rep(i,1,n+1) scanf("%d",s+i);
    rep(i,1,k+1) scanf("%d",c+i);

    rep(i,1,n+1) {
        sts[s[i]] = max(sts[s[i]],p[i]);
    }
    int ans = 0;
    rep(i,1,k+1){
        if(p[c[i]] < sts[s[c[i]]]) ans ++;
    }
    printf("%d\n",ans);
    return 0;
}
