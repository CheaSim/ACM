#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 5e4+20;
int mmax[maxn],mmin[maxn];
int a[maxn];
int n,q;
int lowbit(int x){
    return x&-x;
}
void update(int x){
    for(int i=x;i<=n;i+=lowbit(i)){
        mmax[i] = a[i];
        mmin[i] = a[i];
        for(int j=1;j<lowbit(i);j<<=1){
            mmax[i] = max(mmax[i],mmax[i-j]);
            mmin[i] = min(mmin[i],mmin[i-j]);
        }
    }
}
int query_min(int l,int r){
    int res = INF;
    while(r>=l){
        res = min(a[r],res);
        r--;
        for(;r-lowbit(r)>=l;r-=lowbit(r))
            res = min(mmin[r],res);
    }
    return res;
}
int query_max(int l,int r){
    int res = -INF;
    while(r>=l){
        res = max(a[r],res);
        r--;
        for(;r-lowbit(r)>=l;r-=lowbit(r))
            res = max(mmax[r],res);
    }
    return res;
}
int solve(int l,int r){
    return query_max(l,r)-query_min(l,r);
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d",&n,&q);
    rep(i,1,n+1) mmin[i]=INF,mmax[i]=-INF;
    rep(i,1,n+1){
        scanf("%d",a+i);
        update(i);
    }
    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",solve(l,r));
    }

    return 0;
}
