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
const int maxn = 5e4 + 1000;
int T,n;
int a[maxn],b[maxn],ans[maxn],bit[maxn];
int lowbit(int x){
    return x&-x;
}
int add(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        bit[i] += val;
    }
}
int query(int x){
    int s = 0;
    for(int i=x;i;i-=lowbit(i)){
        s += bit[i];
    }
    return s;
}
int solve(int l,int r,int x){
    int ans = 0;
    while(l<=r){
        int mid = l+r>>1;
        int temp = query(mid);
        if(temp >= x){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        memset(ans,0,sizeof(ans));
        rep(i,1,n+1) add(i,1);
        rep(i,1,n+1) scanf("%d",a+i);
        rep(i,1,n+1) b[i] = a[i] - a[i-1];
        per(i,1,n+1){
            int pos = i-b[i];
            ans[i] = solve(1,n,pos);
            add(ans[i],-1);
        }
        rep(i,1,n+1){
            printf("%d%c",ans[i],i==n?'\n':' ');
        }
    }
    return 0;
}
