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

const int maxn = 5e3 + 6;
int cnt;
struct node{
    int to,next;
}G[maxn];
bool GG[maxn][maxn];
int head[maxn],ind[maxn],pre[maxn];
void add(int u,int v){
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt++;
}
struct Node{  
    int w,h,id,len;
    bool operator<(const Node& a)const{
        if(w < a.w && h < a.h) return 1;
        return 0;
    }
}ep[maxn];
int W,H,t,n;
void Print(int x){
    if(x!=-1){
        Print(pre[x]);
        printf("%d ",ep[x].id);
    }
}
void topo(){
    rep(i,0,n){
        rep(j,0,n){
            if(ep[i]<ep[j]){
                GG[i][j] = 1;
                ind[j]++;
            }
        }
    }
    queue<int>q;
    rep(i,0,n) if(ind[i]==0) q.push(i);
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        rep(i,0,n){
            if(GG[u][i]==0) continue;
            int v= i;
            if(ep[v].len < ep[u].len+1){
                pre[v] = u;
                ep[v].len = ep[u].len + 1;
            }
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("mys.in","r",stdin);
#endif
    memset(head,-1,sizeof(head));
    memset(pre,-1,sizeof(pre));
    cnt = 0;
    scanf("%d%d%d",&t,&W,&H);
    rep(i,0,t){
        int w,h;
        scanf("%d%d",&w,&h);
        if(w <= W || h <= H) continue;
        ep[n].w = w;ep[n].h = h;ep[n].id = i+1;ep[n].len=1;n++; 
    }
    topo();
    int mmax = -1;
    int st = -1;
    rep(i,0,n){
        if(mmax < ep[i].len){
            mmax = ep[i].len;
            st = i;
        }
    }
    if(mmax == -1){
        puts("0");
    }else{
        printf("%d\n",mmax);
        Print(st);
        printf("\n");
    }
    return 0;  
}  
