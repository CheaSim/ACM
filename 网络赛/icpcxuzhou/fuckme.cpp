#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <string>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define MAXN (100000+10)
#define MAXM (300000+10)
#define Ri(a) scanf("%d", &a)
#define Rl(a) scanf("%lld", &a)
#define Rf(a) scanf("%lf", &a)
#define Rs(a) scanf("%s", a)
#define Pi(a) printf("%d\n", (a))
#define Pf(a) printf("%.2lf\n", (a))
#define Pl(a) printf("%lld\n", (a))
#define Ps(a) printf("%s\n", (a))
#define W(a) while((a)--)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define LL long long
#define lson o<<1, l, mid
#define rson o<<1|1, mid+1, r
#define ll o<<1
#define rr o<<1|1
#define PI acos(-1.0)
#pragma comment(linker, "/STACK:102400000,102400000")
#define fi first
#define se second
using namespace std;
struct Edge{
    int to, next;
};
template<typename T>
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
Edge edge[MAXN<<1];
int head[MAXN], edgenum;
void init(){
    edgenum = 0; CLR(head, -1);
}
void addEdge(int u, int v)
{
    edge[edgenum].to = v;
    edge[edgenum].next = head[u];
    head[u] = edgenum++;
}
int son[MAXN], num[MAXN];
int top[MAXN], pos[MAXN], pedge[MAXN], id;
int dep[MAXN], pre[MAXN];
void DFS1(int u, int fa, int d)
{
    dep[u] = d; pre[u] = fa; num[u] = 1; son[u] = -1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == fa) continue;
        DFS1(v, u, d+1);
        num[u] += num[v];
        if(son[u] == -1 || num[son[u]] < num[v])
            son[u] = v;
    }
}
void DFS2(int u, int T)
{
    top[u] = T; pos[u] = ++id; pedge[id] = u;
    if(son[u] == -1) return ;
    DFS2(son[u], T);
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == pre[u] || v == son[u]) continue;
        DFS2(v, v);
    }
}
LL Ans[MAXN];
void Change(int u, int v, LL z, int op)
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(u, v);
            swap(f1, f2);
        }
        Ans[pos[f1]] += z; Ans[pos[u]+1] -= z;
        //Pl(Ans[pos[f1]]);
        u = pre[f1], f1 = top[u];
    }
    if(op == 2 && u == v) return ;
    if(dep[u] > dep[v]) swap(u, v);
    if(op == 1) {Ans[pos[u]] += z, Ans[pos[v]+1] -= z;}
    else {Ans[pos[son[u]]] += z; Ans[pos[v]+1] -= z;}
}
struct Node{
    int op, x, y; LL z;
};
Node In[MAXN];
bool cmp(Node a, Node b){
    return a.op < b.op;
}
int s[MAXN], e[MAXN];
int main()
{
    int t, kcase = 1; Ri(t);
    W(t)
    {
        int n, m; read(n); read(m); init();
        for(int i = 1; i <= n-1; i++)
        {
            scanf("%d%d",s+i,e+i);
            addEdge(s[i], e[i]);
            addEdge(e[i], s[i]);
        }
        DFS1(1, -1, 1); id = 0; DFS2(1, 1);
        for(int i = 1; i <= m; i++)
        {
            char str[10]; Rs(str);
            if(str[3] == '1') In[i].op = 1;
            else In[i].op = 2;
            Ri(In[i].x); Ri(In[i].y); Rl(In[i].z);
        }
        CLR(Ans, 0);
        printf("Case #%d:\n", kcase++);
        for(int i=1; i <= m; i++)
        {
            if(In[i].op == 2) continue;
            Change(In[i].x, In[i].y, In[i].z, 1);
        }
        for(int j = 1; j <= id; j++) Ans[j] += Ans[j-1];
        for(int j = 1; j <= n; j++)
        {
            if(j > 1) printf(" ");
            printf("%lld", Ans[pos[j]]);
        }
        printf("\n"); CLR(Ans, 0);
        for(int i=1; i <= m; i++){
            if(In[i].op == 1) continue;
            Change(In[i].x, In[i].y, In[i].z, 2);
        }
        for(int j = 1; j <= id; j++) Ans[j] += Ans[j-1];
        for(int j = 1; j <= n-1; j++)
        {
            if(j > 1) printf(" ");
            if(dep[s[j]] > dep[e[j]]) swap(s[j], e[j]);
            printf("%lld", Ans[pos[e[j]]]);
        }
        printf("\n");
    }
    return 0;
}
