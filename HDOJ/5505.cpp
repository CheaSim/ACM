#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
//head
ll n,m;

int prime[1100000],primesize,phi[11000000];
bool isprime[11000000];
void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    getlist(4000000);
    while(T--){
        scanf("%llu%llu",&n,&m);
        ll ans = 0;
        bool flag = false;
        for(ll i=1;prime[i]<=n;i++){
            ll cnt1= 0,cnt2 = 0;
            ll t = prime[i];
            while(n%t==0) n/=t,cnt1++;
            while(m%t==0 && m) m/=t,cnt2++;
            if(cnt1>cnt2 ||(cnt1==0 && cnt2>0)){
                flag = true;
                break;
            }
            if(cnt1 == 0) continue;
            ll temp = cnt2/cnt1;
            if(temp*cnt1<cnt2) temp++;
            ans = max(temp,ans);
        }
        if(m>1) flag = true;
        if((n==1 && n!=m) || flag){
            puts("-1");
        }else{
            if(ans==0){
                puts("0");
                continue;
            }
            ll temp = 1;
            int res = 0;
            while(temp<ans) temp<<=1,res++;
            printf("%d\n",res);
        }
    }


    return 0;
}
