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
const int maxn = 1e5 + 10;
int a[maxn];
const int mod = 1e4+7;
int n;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(~scanf("%d",&n)){
        ll ans = 0;
        rep(i,1,n+1){
            int x; scanf("%d",&x);
            ans += 1ll*x;
            a[i] = (1890*x+143)%mod - x;
        }
        ll res = 0;
        deque<int> dq;
        rep(i,2,n+1){
            a[i] += a[i-1];
        }
        rep(i,1,n+1){
            while(!dq.empty() && a[dq.back()]>a[i-1]) dq.pop_back();
            dq.push_back(i-1);
            res = max(res,1ll*a[i]-1ll*a[dq.front()]);
        }
        printf("%lld\n",res+ans);
    }
}
