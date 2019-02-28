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
const int maxn = 2e5+10;
ll dp[maxn][3];
const ll mod = 1e9+7;
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    ll n,l,r;
    cin>>n>>l>>r;
    ll r_0 = r/3;
    ll l_0 = l/3;
    if(l%3) l_0++;
    ll n0 = r_0-l_0+1;
    ll n1 = r_0-l_0;
    ll n2 = r_0-l_0;
    if(r%3==2){
        n1++;n2++;
    }
    if(r%3==1){
        n1++;
    }
    if(l%3==2) n2++;
    if(l%3==1){
        n1++;n2++;
    }
    dp[0][0] = n0;
    dp[0][1] = n1;
    dp[0][2] = n2;
    ll nn[3];
    nn[0] = n0;
    nn[1] = n1;
    nn[2] = n2;
    rep(i,1,n){
        rep(j,0,3){
            rep(k,0,3){
                dp[i][(j+k)%3] += dp[i-1][j] * nn[k];
                dp[i][(j+k)%3] %= mod;
            }
        }
    }
    cout<<dp[n-1][0]<<'\n';


    return 0;
}
