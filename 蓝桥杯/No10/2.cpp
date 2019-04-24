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

int a[10];
const int mod = 1e4;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    a[0] = 1;
    a[1] = 1;
    a[2] = 1;
    rep(i,3,20190324){
        a[3] = (a[0] + a[1] + a[2]) % mod;
        rep(j,0,3) a[j] = a[j+1];
    }
    printf("%d",a[2]);
    return 0;
}
