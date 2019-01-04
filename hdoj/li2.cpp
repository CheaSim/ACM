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
const int maxn = 1e6 + 10;
int n,k;
int a[maxn];
int mmax[maxn];
int mmin[maxn];
int main(){
#ifdef LOCAL
    freopen("12.in","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    rep(i,0,n) scanf("%d",&a[i]);
    int st1,st2,ed1,ed2;
    st1 = st2 = ed2 = ed1 = 0;
    mmax[ed1++] = 0; mmin[ed2++] = 0; 
    rep(i,0,k-1){
        while(st1<ed1 && a[mmax[ed1-1]] <= a[i]) ed1--;
        mmax[ed1++] = i;
        while(st2<ed2 && a[mmin[ed2-1]] >= a[i]) ed2--;
        mmin[ed2++] = i;
    }
    rep(i,k-1,n){
        while(st2<ed2 && i-mmin[st2]+1 > k) st2++;
        while(st2<ed2 && a[mmin[ed2-1]] >= a[i]) ed2--;
        mmin[ed2++] = i;
        printf("%d%c",a[mmin[st2]],i==n-1?'\n':' ');
    }
    rep(i,k-1,n){
        while(st1<ed1 && i-mmax[st1]+1 > k) st1++;
        while(st1<ed1 && a[mmax[ed1-1]] <= a[i]) ed1--;
        mmax[ed1++] = i;
        printf("%d%c",a[mmax[st1]],i==n-1?'\n':' ');
    }
    return 0;
}
