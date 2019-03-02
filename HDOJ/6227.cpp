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
int T,n;
const int maxn = 1e4+10;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,0,n){
            scanf("%d",a+i);
        }
        int res = 0;
        rep(i,1,n-2){
            res += a[i+1]-a[i]-1;
        }
        int ans = max(res+a[1]-a[0]-1,res+a[n-1]-a[n-2]-1);
        printf("%d\n",ans);
    }


    return 0;
}
