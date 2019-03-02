#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define go(i,a,b) for(ll i=a;i<=b;++i)

ll a,b,c,d,v,t;
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
ll test;

ll f(ll x1,ll x2,ll s,ll T){
 	if(T == 0)return 1;

	ll cnt = 0;
	ll now = 0;
	ll c1 = 1,c2 = 1;
	ll i;
	for(i=0;i<T;){
		if(x1*c1 > x2*c2){
			i += x2 * c2;
			c2++;
		}else {
			i += x1 * c1;
			c1++;
		}
		if(i - now >= s)cnt++;
		now = i;
	};
	return cnt;
}
int main(){
#ifdef LOCAL
	freopen("5.in","r",stdin);
#endif
	scanf("%lld",&test);
	while(test--){
		scanf("%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&v,&t);
		ll LCM = lcm(a,c);
		ll A = 0;
		if(t >= LCM){
			A = f(a,c,v,LCM);
			A = A*(t/LCM);
			A += f(a,c,v,t%LCM);
		}else A = f(a,c,v,t);
		ll ans = t / a * b + t / c * d + b + d;
		ans = ans - A;
		printf("%lld\n",ans);
	}
	return 0;
}
