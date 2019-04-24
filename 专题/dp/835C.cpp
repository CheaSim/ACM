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
const int maxp = 1e2+10;
const int maxn = 1e5+10;
int n,q,c;
struct star{
    int x,y;
    int val;
}stars[maxn];
int mx[13][maxp][maxp];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&q,&c);
    rep(i,0,n){
        scanf("%d%d%d",&stars[i].x,&stars[i].y,&stars[i].val);
    }
    c++;
    rep(i,0,c){
        rep(j,0,n){
            int x = stars[j].x , y = stars[j].y, val = stars[j].val;
            mx[i][x][y] += (val+i)%c;
        }
        rep(k,1,100+1){
            rep(z,1,100+1){
                mx[i][k][z] += (mx[i][k-1][z] + mx[i][k][z-1] - mx[i][k-1][z-1]);
            }
        }
    }
    rep(i,0,q){
        int t,x1,x2,y1,y2;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        t = t%c;
        printf("%d\n",mx[t][x2][y2] - mx[t][x1-1][y2] - mx[t][x2][y1-1] + mx[t][x1-1][y1-1]);
    }


    return 0;
}
