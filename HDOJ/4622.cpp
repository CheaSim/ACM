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
const int maxn = 2e3+10;
typedef unsigned long long ull;
int n;
char s[maxn];
ull base[maxn],has[maxn],pos[maxn];
ull bas = 131;
const int mod = 1e5+7;
struct Hash_table{
    int head[mod+2],num;
    ull edgenum[maxn];
    int next[maxn],close[maxn];
    void init(){
        num = 0;
        memset(head,-1,sizeof(head));
    }
    int add(ull val,int id){
        int u = val % mod;
        for(int i=head[u];~i;i=next[i]){
            if(val == edgenum[i]){
                int temp = close[i]; close[i] = id;
                return temp;
            }
        }
        edgenum[num] = val;
        close[num] = id;
        next[num] = head[u];
        head[u] = num++;
        return -1;
    }
}H;
int dp[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    base[0] = 1;
    rep(i,1,maxn) base[i] = base[i-1]*bas;
    while(T--){
        scanf("%s",s+1); int len = strlen(s+1);
        memset(dp,0,sizeof(dp));
        rep(i,1,len+1) has[i] = has[i-1]*bas + s[i] - 'a' + 1;
        for(int x=1;x<=len+1;x++){
            H.init();
            for(int i=1;i+x-1<=len;i++){
                int pos = H.add(has[i+x-1]-base[x]*has[i-1],i);
                dp[i][x+i-1]++;
                if(pos != -1) dp[pos][x+i-1]--;
            }
        }
        per(i,1,len+1) rep(j,i,len+1) 
            dp[i][j] += dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
        int q;scanf("%d",&q);
        while(q--){
            int x,y;scanf("%d%d",&x,&y);
            printf("%d\n",dp[x][y]);
        }
    }

    return 0;
}
