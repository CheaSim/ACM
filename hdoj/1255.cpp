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

int T,n;
const int maxn = 5e4+100;
vector<double> X;
int flag[maxn];
double sum[maxn];
struct node{
    double lx,rx,y;
    int f;
    node(){}
    node(double _lx,double _rx,double _y,int _f){
        lx = _lx; rx = _rx; y = _y; f = _f;
    }
    bool operator<(const node &s){
        return y<s.y;
    }
}L[maxn];
void pushup(int rt,int l,int r){
    if(flag[rt] >= 2) sum[rt] = X[r] - X[l-1];
    else if(l==r) sum[rt] = 0;
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int val,int L,int R,int l,int r,int rt){
    if(l==r){
        flag[rt] += val;
    }else{
        int mid = l+r>>1;
        if(L<=mid) update(val,L,R,lson);
        if(mid<R) update(val,L,R,rson);
    }
    pushup(rt,l,r);
}
void init(){
    memset(sum,0,sizeof(sum));
    memset(flag,0,sizeof(flag));
    X.clear();
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int cnt = 0;
        init();
        rep(i,0,n){
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            L[++cnt] = node(x1,x2,y1,1);
            L[++cnt] = node(x1,x2,y2,-1);
            X.push_back(x1);
            X.push_back(x2);
        }
        sort(X.begin(),X.end());
        sort(L+1,L+1+cnt);
        X.erase(unique(X.begin(),X.end()),X.end());
        int k = X.size();
        double ans = 0.0;
        rep(i,1,cnt){
            int l = lower_bound(X.begin(),X.end(),L[i].lx)-X.begin()+1;
            int r = lower_bound(X.begin(),X.end(),L[i].rx)-X.begin();
            update(L[i].f,l,r,1,k,1);
            ans += sum[1] * (L[i+1].y-L[i].y);
        }
        printf("%0.2f\n",ans);
    }

    return 0;
}
