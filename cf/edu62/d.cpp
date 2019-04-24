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
ll n;
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    cin>>n;
    ll ans = 0;
    rep(i,2,n){
        ans += 1ll*i*(i+1);
    }
    cout<<ans<<'\n';
    return 0;
}
