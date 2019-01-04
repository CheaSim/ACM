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
int n;
double m;
const int maxn = 1e3 + 10;
double a[maxn],b[maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    cin>>n>>m;
    double t = m;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,n){
        if(a[i]==1 || b[i]==1){
            puts("-1");
            return 0;
        }
    }
    m = m+m/(b[0]-1.0);
    rep(i,1,n){
        m = m+ m/(a[i]-1.0);
        m = m + m/(b[i]-1.0);
    }
    m = m+m/(a[0]-1.0);
    printf("%0.15f\n",m-t);
    return 0;
}
