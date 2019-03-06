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
int n;
const int maxn = 1e5 + 200;
vector<double> X;
double sum[maxn];
int flag[maxn];
struct node{
    double lx,rx,y;
    int f;
    node(){}
    node(double _lx,double _rx,double _y,int _f){
        lx = _lx; rx = _rx; y = _y; f = _f;
    }
    bool operator< (const node &s) const{
        return y<s.y;
    }
}L[maxn];
int find(double t,int n){
    int l = 0,r = n-1,mid,ans;
    while(l<=r){
        mid = r+l>>1;
        if(X[mid]<=t){
            l=mid+1; ans=mid;
        }else{
            r = mid - 1;
        }
    }
    return ans+1;
}
void pushup(int l,int r,int rt){
    if(flag[rt]) sum[rt] = X[r] - X[l-1];
    else if(l==r) sum[rt] = 0;
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int val,int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        flag[rt] += val;
    }else{
        int mid = l+r>>1;
        if(L<=mid) update(val,L,R,lson);
        if(mid<R) update(val,L,R,rson);
    }
    pushup(l,r,rt);
}
void init(){
    X.clear();
    memset(flag,0,sizeof(flag));
    memset(sum,0,sizeof(sum));
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int test_case = 1;
    while(scanf("%d",&n) && n){
        init();
        int cnt = 0;
        rep(i,0,n){
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            L[++cnt] = node(x1,x2,y1,1);
            L[++cnt] = node(x1,x2,y2,-1);
            X.push_back(x1);
            X.push_back(x2);
        }
        sort(X.begin(),X.end());
        sort(L+1,L+cnt+1);
        X.erase(unique(X.begin(),X.end()),X.end());
        int k = X.size();
        double ans = 0.0;
        rep(i,1,cnt){
            int l = find(L[i].lx,k);
            int r = find(L[i].rx,k)-1;
            update(L[i].f,l,r,1,k,1);
            ans += sum[1]*(L[i+1].y-L[i].y);
        }
        printf("Test case #%d\n",test_case++);
        printf("Total explored area: %.2lf\n\n",ans);
    }

    return 0;
}
