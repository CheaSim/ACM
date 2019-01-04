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
const int maxn = 500+10;
int n,m,k,q,maxt;
struct node{
    int x,y,t;
    node(int x,int y,int t):x(x),y(y),t(t){}
    node(){}
    bool operator<(const node& a)const{
        return t < a.t;
    }
}pl[maxn*maxn];  
int mx[maxn][maxn];
bool check(){
    rep(i,1,n+1) rep(j,1,m+1) mx[i][j] += mx[i][j-1];
    rep(j,1,m+1) rep(i,1,n+1) mx[i][j] += mx[i-1][j];
    rep(i,k,n+1){
        rep(j,k,m+1){
            if(mx[i][j] - mx[i-k][j] - mx[i][j-k] + mx[i-k][j-k] == k*k)
                return false;
        }
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d%d%d",&n,&m,&k,&q);
    rep(i,0,q){
        int x,y,t;scanf("%d%d%d",&x,&y,&t);
        pl[i] = node(x,y,t); maxt = max(t,maxt);
    }
    int l,r,mid;
    l = 0;r = maxt+1;
    sort(pl,pl+q);
    int c= 0;
    while(l<r){
        mid = (l+r)>>1;
        int cnt = 0;bool flag = false;
        memset(mx,0,sizeof(mx));
        int now = 0;
        while(pl[now].t <= mid && now<q){
            mx[pl[now].x][pl[now].y] = 1;
            now++;
        }
        if(check()==0) flag = 1;
        if(!flag) l = mid+1;
        else r = mid;
    }
    printf("%d\n",l>maxt?-1:l);
    return 0;
}
