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
const int maxn = 1e6+10;
int dp[maxn];
int a[maxn],b[maxn],c[maxn];
int n,t;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        rep(i,0,n){
            scanf("%d%d%d",a+i,b+i,c+i);
        }
        memset(dp,0,sizeof(dp));
        rep(i,0,t+1){
            
        }
    }


    return 0;
}

