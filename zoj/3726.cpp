#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head

const int maxn = 1e5 + 10;
vector<int> X;
int n,m;
ll mmin[maxn<<2];
ll a[maxn];
void pushup(int rt){
    mmin[rt] = min(mmin[rt<<1], mmin[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        mmin[rt] = 1ll*a[l]*X[l-1];
        return;
    }
    int mid = l+r>>1;
    build(lson); build(rson);
    pushup(rt);
}  
ll query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        return mmin[rt];
    }
    int mid = l+r>>1;
    ll ans = 1e17;
    if(L<=mid) ans = min(ans,query(L,R,lson));
    if(mid<R) ans = min(ans,query(L,R,rson));
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        X.clear();
        rep(i,1,n+1){
            ll x,b;scanf("%lld%lld",&x,&b);
            a[i] = b;X.push_back(x);
        }
        build(1,n,1);
        while(m--){
            int num;scanf("%d",&num);
            int pos = upper_bound(X.begin(),X.end(),num)-X.begin();
            ll ans = 1ll*num*a[pos];
            if(pos<n) ans = min(ans,query(pos+1,n,1,n,1));
            printf("%lld\n",ans);
        }
    }

    return 0;
}
