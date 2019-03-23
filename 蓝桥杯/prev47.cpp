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

const int maxn = 55;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int n;scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",a+i);
    }
    int ans = 1;
    int ill = abs(a[0]);
    rep(i,1,n){
        if(abs(a[i]) > ill && a[i] < 0) ans++;
        if(abs(a[i]) < ill && a[i] > 0) ans++;
    }
    printf("%d\n",ans);


    return 0;
}
