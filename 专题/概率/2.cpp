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
const int maxn = 110;
int T,n;
double dp[maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d",&n);
        rep(i,1,n+1) cin>>dp[i]; 
        per(i,1,n){
            double sum = 0.0;
            double cnt = 0;
            rep(j,i+1,i+7){
                if(j<=n) sum+=dp[j],cnt++;
            }
            dp[i] += sum/cnt;
        }
        printf("Case %d: %0.9f\n",test_case,dp[1]);
    }

    return 0;
}
