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
ll p;
int check(ll x){
    ll temp = 3*x*x+3*x+1ll;
    if(temp == p) return 0;
    if(temp > p) return 1;
    if(temp < p) return -1;
}
bool solve(ll l,ll r){
    ll mid = l+r>>1;
    while(l<=r){
        mid = l+r>>1;
        int res = check(mid);
        if(res==0) return true;
        else if(res==1){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return false;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld",&p);
        if(solve(1,1e6)){
            puts("YES");
        }else{
            puts("NO");
        }
    }

    return 0;
}
