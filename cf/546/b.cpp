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
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int n,a;
    scanf("%d%d",&n,&a);
    int ans = 0;
    if(n&1) ans+=3,ans += (n-1)*3;
    else ans += n*3;
    int mmin = min(n-a,a-1);
    ans += mmin;
    printf("%d\n",ans);


    return 0;
}
