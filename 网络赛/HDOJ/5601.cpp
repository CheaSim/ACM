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
const int maxn = 1e3+10;
int mx[maxn][maxn];
int vis[maxn][maxn];
int flag = 0,cnt = 0;
void ans(int x){
    if(x) puts("YES");
    else puts("NO");
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        flag = 0;
        int t = 0;
        vector<int> ve;
        rep(i,0,n){
            int x = 0;
            rep(j,0,m){
                scanf("%d",&mx[i][j]);
                if(mx[i][j] == 0) x++;
            }
            ve.push_back(x&1);
        }
        int xx = 0;
        for(auto x:ve){
            if(x==0) xx++;
        }
        ans(xx&1);
}

    return 0;
}
