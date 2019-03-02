#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
template <typename T>  
inline bool read (T &ret) {  
    char c;  
    int sgn;  
    if (c = getchar(), c == EOF) return 0; //EOF  
    while (c != '-' && (c < '0' || c > '9') ) {
        if((c = getchar()) == EOF) return 0;
    }
    sgn = (c == '-') ? -1 : 1;  
    ret = (c == '-') ? 0 : (c - '0');  
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template<typename T>
void print(T x) {
    static char s[33], *s1; s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) putchar('-'), x = -x;
    while(x) *s1++ = (x % 10 + '0'), x /= 10;
    while(s1-- != s) putchar(*s1);
}
template<typename T>
void println(T x) {
    print(x); putchar('\n');
}
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 1e4+100;
int dp[maxn][22],order[maxn*2],dep[maxn*2],head[maxn],fir[maxn],ans1[maxn];
int ind[maxn],fa[maxn];
ll des[maxn],add[maxn][2];
int n,cnt;
struct ST{
    void init(int n){
        rep(i,1,n+1) dp[i][0] = i;
        for(int j=1;(1<<j)<=n;j++){
            for(int i=1;i+(1<<j)-1<=n;i++){
                int a = dp[i][j-1],b = dp[i+(1<<(j-1))][j-1];
                dp[i][j] = dep[a]<dep[b]?a:b;
            }
        }
    }
    int rmq(int l,int r){
        int k = 0;
        while((1<<(k+1))<=r-l+1) k++;
        int a = dp[l][k], b = dp[r-(1<<k)+1][k];
        return dep[a]<dep[b]?a:b;
    }
    int lca(int x,int y){
        int u = fir[x],v = fir[v];
        int res;
        if(u>v) res = rmq(v,u);
        else res = rmq(u,v);
        return order[res];
    }
}st;
void dfs(int u,int deep){
    vis[u] = 1;
    order[++tot] = u;
    fir[u] = tot;
    dep[tot] = deep;
    for(int i=head[u];~i;i=G[i].next){
        int v = G[i].to;
        if(vis[v]) continue;
        ind[u]++;
        fa[v] = u;
        dfs(v,deep+1);
        order[++tot] = u;
        dep[tot] = deep;
    }
}
struct edge{
    int to,next,val;
}G[maxn<<1];
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
void init(){
    cnt = tot = 0;
    memset(head,-1,sizeof(int)*(n+1));
    memset(add,0,sizeof(add));
    memset(ind,0,sizeof(int)*(n+1));
    memset(vis,0,sizeof(int)*(n+1));
    fa[1] = 1;
}
void solve(){
    queue<int> q;
    rep(i,1,n+1){
        if(ind[i]==0) q.push(i);
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        ans1
    }
}
char op[20];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T,q;scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d%d",&n,&q);
        init();
        rep(i,0,n-1){
            int u,v;read(u); read(v);
            add(u,v);add(v,u);
        }
        dfs(1,0);
        st.init(n*2-1);
        rep(i,0,q){
            scanf("%s",op);int u,v,val;
            read(u); read(v); read(val);
            if(s[3] == '1'){
                add[u][0] += val;
                add[v][0] += val;
                int x = st.lca(u,v);
                add[x][0] -= val;
                des[x] -= val;
            }else{
                add[u][1] += val;
                add[v][1] += val;
                int x = st.lca(u,v);
                add[x][1] -= 2*val;
            }
        }
    }


    return 0;
}
