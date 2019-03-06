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
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int T,n;
const int maxn = 1e2+10;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    rep(test_case,1,T+1){
        int m = 0;int sum = 0;
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",a+i);
        rep(i,0,n){
            sum += abs(a[i]);
            if(a[i]>=0) m++;
        }
        printf("Case %d: ",test_case);
        if(m==0) puts("inf");
        else{
            printf("%d/%d\n",sum/gcd(sum,m),m/gcd(sum,m));
        }
    }


    return 0;
}
