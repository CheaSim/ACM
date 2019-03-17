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

int n,m;
const int maxn = 5e2+10;
int mx1[maxn][maxn], mx2[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,n) rep(j,0,m) scanf("%d",mx1[i]+j);
    rep(i,0,n) rep(j,0,m) scanf("%d",mx2[i]+j);
    bool ans = true;
    n = max(n,m);
    rep(i,0,n){
        map<int,int>mmp;
        rep(j,0,i+1){
            mmp[mx1[i-j][j]]++;
        }
        rep(j,0,i+1){
            mmp[mx2[i-j][j]]--;
            if(mmp[mx2[i-j][j]] == 0) mmp.erase(mx2[i-j][j]);
        }
        if(mmp.size()>0) ans = false;
        if(!ans) break;
    }
    rep(i,0,n){
        map<int,int>mmp;
        rep(j,0,n-i){
            mmp[mx1[n-j][i+j]]++;
        }
        rep(j,0,n-i){
            mmp[mx2[n-j][i+j]]--;
            if(mmp[mx2[n-j][i+j]] == 0) mmp.erase(mx2[n-j][i+j]);
        }
        if(mmp.size()>0) ans = false;
        if(!ans) break;
    }

    if(ans) puts("YES");
    else puts("NO");
    return 0;
}
