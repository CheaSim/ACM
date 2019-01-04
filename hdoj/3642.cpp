#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 1e4 +10;
int n;
vector<int> X;
vector<int> Z;
struct node{
    int lx,rx,y,lz,rz;
    int f;
    node(){}
    node(int _lx,int _rx,int _y,int _f,int _lz,int _rz){
        lx = _lx; rx = _rx; y = _y; f = _f;
        lz = _lz; rz = _rz;
    }
    bool operator<(const node &s){
        return y<s.y;
    }
}L[maxn<<2],tmp[maxn<<2];
int sum1[maxn],sum2[maxn],sum3[maxn],flag[maxn];
void pushup(int rt,int l,int r){
    int lc = rt<<1, rc = rt<<1|1;
    if(flag[rt]>=3){
        sum3[rt] = sum2[rt] = sum1[rt] = X[r]-X[l-1];
    }else if(flag[rt]==2){
        sum2[rt] = sum1[rt] = X[r]-X[l-1];
        if(l==r) sum3[rt] = 0;
        else sum3[rt] = sum1[lc]+sum1[rc];
    }else if(flag[rt]==1){
        sum1[rt] = X[r]-X[l-1];
        if(l==r) sum2[rt]=sum3[rt] = 0;
        else{
            sum2[rt] = sum1[rc]+sum1[lc];
            sum3[rt] = sum2[rc]+sum2[lc];
        }
    }else{
        if(l==r) sum1[rt]=sum2[rt]=sum3[rt]=0;
        else{
            sum1[rt] = sum1[lc]+sum1[rc];
            sum2[rt] = sum2[rc]+sum2[lc];
            sum3[rt] = sum3[lc]+sum3[rc];
        }
    }
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        flag[rt] += val;
    }else{
        int mid = l+r>>1;
        if(L<=mid) update(val,L,R,lson);
        if(mid<R) update(val,L,R,rson);
    }
    pushup(rt,l,r);
}
void init(){
    memset(flag,0,sizeof(flag));
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    memset(sum3,0,sizeof(sum3));
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d",&n);
        init();
        X.clear(); Z.clear();
        int cnt = 0;
        rep(i,0,n){
            int x1,x2,y1,y2,z1,z2;
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            L[++cnt] = node(x1,x2,y1,1,z1,z2);
            L[++cnt] = node(x1,x2,y2,-1,z1,z2);
            X.pb(x1);X.pb(x2);
            Z.pb(z1);Z.pb(z2);
        }
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        sort(Z.begin(),Z.end());
        Z.erase(unique(Z.begin(),Z.end()),Z.end());
        sort(L+1,L+1+cnt);
        ll ans = 0;
        int len = Z.size();
        int k = X.size();
        rep(i,0,len-1){
            int tot = 0;
            rep(j,1,cnt+1) if(L[j].lz<=Z[i] && L[j].rz>Z[i]) tmp[tot++] = L[j];
            //sort(tmp,tmp+tot);
            init();
            ll area = 0;
            rep(j,0,tot-1){
                int l = lower_bound(X.begin(),X.end(),tmp[j].lx)-X.begin()+1;
                int r = lower_bound(X.begin(),X.end(),tmp[j].rx)-X.begin();
                update(tmp[j].f,l,r,1,k,1);
                area += (ll) sum3[1] *(tmp[j+1].y-tmp[j].y);
            }
            ans += area*(Z[i+1]-Z[i]);
        }
        printf("Case %d: %lld\n",test_case,ans);
    }

    return 0;
}
