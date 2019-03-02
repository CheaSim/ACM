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
int w,h,a,d,y;
ll ans;
const int maxn = 1e3+10;
struct node{
    int q,p,n,m;
    node(){}
    node(int qq,int pp,int nn,int mm):q(qq),p(pp),n(nn),m(mm){}
}corns[maxn];

void solve(int id){
    int x = h % 3; int y = w % 3;
    int xx = h/3; int yy = w/3;
    int p = corns[id].p, q = corns[id].q, n = corns[id].n;
    ll day = d/n;
    int cnt = 0;
    while(cnt*p<q) cnt++;
    ll temp = 1ll*(h-x)*(w-y)*p - 1ll*xx*yy*q;
    ans = max(ans,temp*day);
    if(cnt<3){

    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&w,&h,&a,&d,&y);
        ans = y;
        rep(i,0,a){
            int q,p,n,m; scanf("%d%d%d%d",&q,&p,&n,&m);
            corns[i] = node(q,p,n,m);
        }
        int id1 = 0,id2 = 0;
        double mmax1 = -INF,mmax2 = -INF;
        rep(i,0,a){
            if(corns[i].n > d || corns[i].m > d) continue;
            double temp;
            if(corns[i].n){
                tmep = (double)(corns[i].p-corns[i].q)/corns[i].n;
                if(temp>mmax1){
                    mmax1 = tmep;
                    id1 = i;
                }
            }else{
                temp = (double)(corns[i].p-corns[i].q)/corns[i].m;
                if(temp>mmax2){
                    mmax2 = temp;
                    id2 = i;
                }
            }
        }
    }

    return 0;
}
