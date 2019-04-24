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

const int maxn = 1e4+10;
int a[maxn];
int n;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,1,n+1){
        scanf("%d",a+i);
    }
    int ans = 0;
    for(int i=1;i<n+1;i++){
        int mmax = a[i];
        while(mmax != i){
            i++;
            mmax = max(a[i],mmax);
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
