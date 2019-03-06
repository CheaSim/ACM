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

const int maxn = 5e4+10;
struct node{
    int next,to;
}G[maxn<<1];
int head[maxn],cnt;
int sum[maxn],mmax[maxn];
void addedge(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
int n;
void init(){
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(sum,0,sizeof(int)*(n+1));
    memset(mmax,0,sizeof(int)*(n+1));
}
void dfs(int u,int fa){
    sum[u] = 1;
    mmax[u] = 1;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(v==fa) continue;
        dfs(v,u);
        sum[u] += sum[v];
        mmax[u] = max(mmax[u],sum[v]);
    }
    mmax[u] = max(mmax[u],n-sum[u]);
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d",&n);
    init();
    rep(i,0,n-1){
        int u,v;scanf("%d%d",&u,&v);
        addedge(u,v); addedge(v,u);
    }
    dfs(1,0);
    int m = INF;
    rep(i,1,n+1){
        m = min(m,mmax[i]);
    }
    vector<int> ans;
    rep(i,1,n+1){
        if(mmax[i]==m)
            ans.push_back(i);
    }
    int len = ans.size();
    rep(i,0,len){
        printf("%d%c",ans[i],i==len-1?'\n':' ');
    }
    return 0;
}
