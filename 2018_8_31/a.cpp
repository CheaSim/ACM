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
int n,k;
const int maxn = 60;
char s[maxn];
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int len = strlen(s);
    rep(i,0,n) a[i] = s[i] -'a'+1;
    sort(a,a+len);
    int ans = 0;int t = 0;int si = -3;
    rep(i,0,len){
        if(si<a[i]-1 && t<k){
            ans +=a[i];
            t++;
            si = a[i];
        }
    }
    if(t==k){
        printf("%d\n",ans);
    }else{
        puts("-1");
    }
    return 0;
}
