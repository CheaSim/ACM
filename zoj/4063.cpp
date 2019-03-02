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
const int maxn = (1<<10) + 10;
int ans[maxn][maxn];
void Swap(int row,int x,int len,int go){
    rep(i,x,x+len){
        swap(ans[row][i],ans[row][i+go]);
    }
}
int n,k;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    rep(i,0,maxn){
        rep(j,0,maxn){
            ans[i][j] = j;
        }
    }
    rep(i,1,maxn){
        rep(j,0,11){
            if( ((i>>j)&1)){
                for(int x=1;x+pow(2,j+1)<=maxn;x+=pow(2,j+1)){
                    Swap(i,x,1<<j,1<<j);
                }
            }
        }
    }
    while(T--){
        scanf("%d%d",&n,&k);
        int cnt = 0;
        while(((n>>cnt)&1)==0) cnt++;

        cout<<(n&(-n))<<endl;
        if(k>=(n&(-n))) {puts("Impossible");continue;}
        rep(i,1,k+1){
            rep(j,1,n+1){
                printf("%d%c",ans[i][j],j==n?'\n':' ');
            }
        }
    }
    return 0;
}
