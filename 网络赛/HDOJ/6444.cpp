#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
int n,k,m;
ll s;
const int maxn = 1e4+100;
ll a[maxn];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
ll pre[maxn*3];
ll solve(vector<ll> ve,int len,int lim){
    rep(i,1,len*3+1) pre[i] = pre[i-1]+ve[(i-1)%len];
    deque<int> dq;
    ll ans = 0;
    rep(i,1,len*3+1){
        while(!dq.empty() && i-dq.front()>lim) dq.pop_front();
        while(!dq.empty() && pre[dq.back()]>pre[i-1]) dq.pop_back();
        dq.pb(i-1);
        ans = max(ans,pre[i]-pre[dq.front()]);
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d%lld%d%d",&n,&s,&m,&k);
        rep(i,0,n) scanf("%lld",a+i);
        int loop = gcd(n,k);
        int len = m % (n/loop);
        int cnt = n/loop;
        ll ans = s;
        rep(i,0,loop){
            vector<ll> ve;
            ll sum = 0;
            rep(j,0,cnt){
                ve.pb(a[(i+j*k)%n]);
                sum += ve[j];
            }
            if(m<=cnt){
                sum = solve(ve,cnt,m);
                ans = min(ans,s-sum);
                continue;
            }
            sum *= 1ll*(m/cnt-1);
            if(sum>0)
                sum += solve(ve,cnt,len+cnt);
            else
                sum = solve(ve,cnt,cnt+len);
            ans = min(ans,s-sum);
        }
        ans = max((ll)0,ans);
        printf("Case #%d: %lld\n",test_case,ans);
    }


    return 0;
}
