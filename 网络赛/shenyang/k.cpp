#include<bits/stdc++.h>
#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;

#define debug puts("YES");
#define rep(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define read(x,y) scanf("%d%d",&x,&y)

#define lrt int l,int r,int rt
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ll long long
const int  maxn =1e2+5;
const int mod=1e9+7;
ll powmod(ll x,ll y) {ll t;for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod;return t;}
ll gcd(ll x,ll y)  {  return y==0?x:gcd(y,x%y); }

char c[maxn];
int num[]={2,3,5,7,11,13,17,23,31,37,53,71,73,311,113,713,317,131,731,137,371,173};
int table[]={0,1,2,3,3,5,5,7,7,7};
char ans[maxn];

int main()
{
    sort(num,num+22);
    int t;scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%s",c);
        int len=strlen(c);
        if(len>3) printf("Case #%d: %d\n",ca,731);
        else
        {
            int t=0;
            for(int i=0;i<len;i++) t=t*10+(c[i]-'0');
            int pos=upper_bound(num,num+24,t)-num;
            printf("Case #%d: %d\n",ca,t);
            else printf("Case #%d: %d\n",ca,num[pos-1]);
        }
    }
    return 0;
}
