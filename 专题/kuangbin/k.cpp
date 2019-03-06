#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
template <typename T>  
inline bool read (T &ret) {  
    char c;  
    int sgn;  
    if (c = getchar(), c == EOF) return 0; //EOF  
    while (c != '-' && (c < '0' || c > '9') ) {
        if((c = getchar()) == EOF) return 0;
    }
    sgn = (c == '-') ? -1 : 1;  
    ret = (c == '-') ? 0 : (c - '0');  
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');  
    ret *= sgn;  
    return 1;  
}  
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const ll maxn = 1e5 + 20;
const ll mod = 1e4 + 7;
ll pp[mod+20][4],sum[4][maxn<<2];
ll lazy[maxn<<2][4];
int n,m,x,y,val;
void init(){
    memset(sum,0,sizeof(sum));
    memset(lazy,0,sizeof(lazy));
    rep(i,0,maxn){
        lazy[i][2] = 1;
    }
}
void pushup(int rt){
    rep(i,1,4){
        sum[i][rt] = (sum[i][rt<<1] + sum[i][rt<<1|1])%mod;
    }
}
void pushdown(int rt,ll len){
    if(lazy[rt][3]){
        ll c = lazy[rt][3]%mod;
        lazy[rt<<1][1] = lazy[rt<<1|1][1] = 0;
        lazy[rt<<1][2] = lazy[rt<<1|1][2] = 1;
        lazy[rt<<1][3] = lazy[rt<<1|1][3] = c;
        sum[1][rt<<1] = c*(len-len/2);
        sum[1][rt<<1|1] = c*(len/2);
        sum[2][rt<<1] = pp[c][2]*(len-len/2)%mod;
        sum[2][rt<<1|1] = pp[c][2]*(len/2)%mod;
        sum[3][rt<<1] = pp[c][3]*(len-len/2)%mod;
        sum[3][rt<<1|1] = pp[c][3]*(len/2)%mod;
        lazy[rt][3] = 0;
        rep(i,1,4){
            sum[i][rt<<1] %= mod;
            sum[i][rt<<1|1] %= mod;
        }
    }
    if(lazy[rt][2]!=1){
        ll c = lazy[rt][2]%mod;
        rep(i,1,4){
            sum[i][rt<<1] *= pp[c][i];
            sum[i][rt<<1|1] *= pp[c][i];
        }
        rep(i,1,3){
            lazy[rt<<1][i] = (lazy[rt<<1][i]%mod)*c%mod;
            lazy[rt<<1|1][i] = (lazy[rt<<1|1][i]%mod)*c%mod;
        }
        lazy[rt][2] = 1;
        rep(i,1,4){
            sum[i][rt<<1] %= mod;
            sum[i][rt<<1|1] %= mod;
        }
    }
    if(lazy[rt][1]){
        ll c = lazy[rt][1]%mod;
        lazy[rt<<1][1] += c;
        lazy[rt<<1|1][1] += c;
        lazy[rt<<1][1] %= mod;
        lazy[rt<<1|1][1] %= mod;
        sum[3][rt<<1] += 1ll*3*sum[2][rt<<1]%mod*c%mod + c*c%mod*c%mod*(len-len/2)%mod + 3*sum[1][rt<<1]%mod*c%mod*c%mod;
        sum[3][rt<<1|1] += 1ll*3*sum[2][rt<<1|1]%mod*c%mod + 3*sum[1][rt<<1|1]*c%mod*c%mod + c*c%mod*c%mod*(len/2)%mod;
        sum[2][rt<<1] += 1ll*2*sum[1][rt<<1]%mod*c%mod + c*c%mod*(len-len/2)%mod;
        sum[2][rt<<1|1] += 1ll*2*sum[1][rt<<1|1]%mod*c%mod + c*c%mod*(len/2)%mod;
        sum[1][rt<<1] += c*(len-len/2);
        sum[1][rt<<1|1] += c*(len/2);
        lazy[rt][1] = 0;
    }
    rep(i,1,4){
        sum[i][rt<<1] %= mod;
        sum[i][rt<<1|1] %= mod;
        lazy[rt<<1|1][i] %= mod;
        lazy[rt<<1][i] %= mod;
    }
}
void update(int op,ll c,ll L,ll R,ll l,ll r,ll rt){
    if(L<=l && r<=R){
        if(op==1){
            sum[3][rt] += 1ll*3*sum[2][rt]*c%mod+1ll*3*sum[1][rt]*c%mod*c%mod+c*c%mod*c%mod*(r-l+1)%mod;
            sum[2][rt] += sum[1][rt]%mod*c%mod*2%mod+c*c%mod*(r-l+1)%mod;
            sum[1][rt] += 1ll*(r-l+1)*c%mod;
            lazy[rt][1] += c;
            lazy[rt][1] %= mod;
        }else if(op==2){
            rep(i,1,4) sum[i][rt] *= pp[c][i];
            lazy[rt][2] *= c;
            lazy[rt][2] %= mod;
            lazy[rt][1] *= c;
            lazy[rt][1] %= mod;
        }else{
            rep(i,1,4) sum[i][rt] = pp[c][i]*(r-l+1)%mod;
            lazy[rt][3] = c;
            lazy[rt][1] = 0;lazy[rt][2] = 1;
        }
        rep(i,1,4)  sum[i][rt] %= mod;
        return;
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    if(L<=mid) update(op,c,L,R,lson);
    if(mid<R) update(op,c,L,R,rson);
    pushup(rt);
}
ll query(int op,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        return sum[op][rt];
    }
    pushdown(rt,r-l+1);
    int mid = l+r>>1;
    ll ans = 0;
    if(L<=mid) (ans += query(op,L,R,lson)%mod)%=mod;
    if(mid<R) (ans += query(op,L,R,rson)%mod)%mod;
    pushup(rt);
    return ans%mod;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
#endif
    rep(i,1,mod+1) pp[i][1] = i%mod;
    rep(i,1,mod+1){
        rep(j,2,4){
            pp[i][j] = (ll)pp[i][j-1]*i%mod;
        }
    }
    while(~scanf("%d%d",&n,&m)){
        init();
        rep(i,0,m){
            int op;read(op); read(x);read(y);read(val);
            if(op==4){
                printf("%lld\n",query(val,x,y,1,n,1));
            }else{
                update(op,val,x,y,1,n,1);
            }
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
