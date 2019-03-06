#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=510000;
struct atom{
    int x;
    long long w;
    void scan(){
        scanf("%d%lld",&x,&w);
    }
}A[N];
int compare(atom k1,atom k2){
    return k1.x<k2.x;
}
int n;
long long T;
long long B[N],C[N];
long long calc(int l,int r,int m){
    long long L=1ll*(B[m]-B[l-1])*A[m].x-(C[m]-C[l-1]);
    long long R=C[r]-C[m]-1ll*(B[r]-B[m])*A[m].x;
    //cout<<l<<" "<<r<<" "<<m<<" "<<L+R<<endl;
    return L+R;
}
void del(int &l,int &r,int m){
    if (abs(A[l].x-A[m].x)>abs(A[r].x-A[m].x)) l++;
    else r--;
}
void add(int &l,int &r,int m){
    if (l==1&&r==n){
        cout<<B[n]<<endl; exit(0);
    }
    if (l==1) r++;
    else if (r==n) l--;
    else if (abs(A[l-1].x-A[m].x)<abs(A[r+1].x-A[m].x)) l--;
    else r++;
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d%lld",&n,&T); T/=2;
    for (int i=1;i<=n;i++)scanf("%d",&A[i].x);
    for (int i=1;i<=n;i++) scanf("%lld",&A[i].w);
    int pre=n; n=1;
    for (int i=2;i<=pre;i++)
        if (A[i].x==A[n].x) A[n].w+=A[i].w; else A[++n]=A[i];
    for (int i=1;i<=n;i++) B[i]=B[i-1]+A[i].w,C[i]=C[i-1]+1ll*A[i].x*A[i].w;
    int l=1,r=1; long long ans=0;
    for (int i=1;i<=n;i++){
        r=max(r,i);
        while (r<n&&A[r+1].x-A[i].x<A[i].x-A[l].x) r++;
        while (calc(l,r,i)>T) del(l,r,i);
        while (calc(l,r,i)<=T) add(l,r,i);
        long long now=calc(l,r,i);
        long long sum=B[r]-B[l-1];
        long long del=now-T;
        int k1=max(abs(A[i].x-A[l].x),abs(A[i].x-A[r].x));
        sum-=del/k1;
        if (del%k1) sum--;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
