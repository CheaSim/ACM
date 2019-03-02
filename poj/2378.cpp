#include <iostream>//数据输入输出流
#include <cstring>//字符串操作函数
#include <cstdio>//C的输入输出
#include <cstdlib>//定义杂项函数及内存分配函数
#include <cmath>//C中的数学函数
#include <string>//c++中的string类 他不能用strcpy等c函数去操作
#include <vector>//STL vetor
#include <list>//STL list
#include <map>// STL map
#include <queue>// STL queue
#include <stack>//sTL stack
#include <bitset>//bitset可按位定义串
//比如：bitset <1000> all;定义一个1000位的串
#include <algorithm>//STL各种算法 比如 swap sort merge max min 比较
#include <numeric>//常用数字操作 一般和algorithm搭配使用
#include <functional>//STL定义运算函数（代替运算符）
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
struct node{
    int next,to,val;
}G[maxn<<1];
int cnt,head[maxn];
void addedge(int u,int v,int val){
    G[cnt].to = v;
    G[cnt].val = val;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
ll dp[maxn][55];
int sum[maxn],dis[maxn];
int n,k;
ll inf;
void dfs(int u,int fa){
    dp[u][1] = 0;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        dfs(v,u);
        for(int x=k-1;x>=1;x--){
            for(int y=1;y+x<=k;y++){
                if(dp[u][x] == inf || dp[v][y] == inf) continue;
                dp[u][x+y] = min(1ll*(k-y)*y*G[i].val+dp[v][y]+dp[u][x],dp[u][x+y]);
            }
        }
    }
}
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(dp,0xf,sizeof(dp));
    memset(sum,0,sizeof(sum));
    inf = dp[0][0];
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        init();
        rep(i,0,n-1){
            int u,v,val;scanf("%d%d%d",&u,&v,&val);
            addedge(u,v,val); addedge(v,u,val);
        }
        dfs(1,0);
        ll ans = inf;
        rep(i,1,n+1){
            ans = min(ans,dp[i][k]*2);
        }
        printf("%lld\n",ans);
    }
    return 0;

}
