#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head -------------------------------------------
const int maxn = 1020;
int n, m;
ll ans;
char s[maxn];
int mx[maxn][maxn];
int nxt[maxn],gor[maxn][maxn],god[maxn][maxn],mg[maxn];
int main(){
#ifdef LOCAL
    freopen("10.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,n){
        scanf("%s",s);
        rep(j,0,m){
            if(s[j]<='z' && s[j]>='a') mx[i][j] = s[j]-'a';
            else mx[i][j] = s[j] - 'A' + 26;
        }
    }
    rep(i,0,n){
        rep(j,0,52) nxt[j] = m;
        gor[i][m] = m;
        per(j,0,m){
            gor[i][j] = gor[i][j+1];
            gor[i][j] = min(gor[i][j],nxt[mx[i][j]]);
            nxt[mx[i][j]] = j;
        }
    }
    rep(j,0,m){
        rep(i,0,52) nxt[i] = n;
        god[n][j] = n;
        per(i,0,n){
            god[i][j] = god[i+1][j];
            god[i][j] = min(god[i][j],nxt[mx[i][j]]);
            nxt[mx[i][j]] = i;
        }
    }
    rep(i,0,n) rep(j,0,m){
        int g = god[i][j];
        rep(c,j,gor[i][j]){
            g = min(g,god[i][c]);
            mg[c] = g;
        }
        g = gor[i][j]-1;
        rep(c,i,god[i][j]){
            g = min(g,gor[c][j]-1);
            while(mg[g]<=c && g) g--;
            ans += g-j+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
