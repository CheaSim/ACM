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
int n,m,y;
const int maxn = 1e3+10;
double a[maxn];
double b[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&y);
        double sum1 = 0.0;
        double sum2 = 0.0;
        rep(i,0,n) scanf("%lf",a+i), sum1 += a[i];
        rep(i,0,m) scanf("%lf",b+i), sum2 += b[i];
        double aa = sum1/n;
        double bb = sum2/m;
        double p = 1.0*n/(n+m);
        double q = 1.0*m/(n+m);
        double ans = p*bb*q/(1.0-q)/(1.0-q) + p*aa/(1.0-q);
        if(ans > y) puts("Wait");
        else puts("Go");
    }

    return 0;
}
