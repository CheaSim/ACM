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
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
const int maxn = 1e5+10;
ll fib[maxn];
void Fib(ll a,ll b,ll c,ll d){
    ll t = a*b/gcd(a,b);
    t = c*t/gcd(t,c);
    t = d*t/gcd(t,d);
    fib[1] = 1;
    fib[2] = 1;
    rep(i,3,maxn){
        fib[i] = (fib[i-1] + fib[i-2]) % t;
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    ll a,b,c,d;
    ll s,t;
    scanf("%lld%lld",&s,&t);
    cin>>a>>b>>c>>d;
    Fib(a,b,c,d);
    vector<int> ans;
    rep(i,s,t+1){
        ll temp = fib[i];
        if(temp%a && temp%b && temp%c && temp%d){
            ans.push_back(i);
        }
    }
    int sz = ans.size();
    rep(i,0,sz){
        printf("%d%c",ans[i],i==sz-1?'\n':' ');
    }
    return 0;
}
