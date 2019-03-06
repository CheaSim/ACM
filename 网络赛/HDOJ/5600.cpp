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
const int maxn = 1e6+100;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",a+i);
        int t = 0;
        rep(i,0,n) if(a[i]==0) t++;
        if(t&1) ans(0);
        else ans(1);
    }


    return 0;
}
