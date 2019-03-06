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
vector<ll> a;
ll inf = 1ll<<50;
int n;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        a.clear();
        scanf("%d",&n);
        a.push_back(inf);
        rep(i,1,n+1){
            ll x; scanf("%lld",&x);
            a.push_back(x);
        }
        a.push_back(-1);
        a.erase(unique(a.begin(),a.end()),a.end());
        int len = a.size();
        int down = -1;int cnt = 0;ll ans = 0;
        rep(i,1,len-1){
            if(a[i] <a[i-1] && a[i]<a[i+1]){
                down = i;
            }
            if(a[i]>a[i+1]&&a[i]>a[i-1]){

                cnt+=2;
                ans += a[i]-a[down];
            }
        }
        printf("%lld %d\n",ans,cnt);
    }
    return 0;
}
