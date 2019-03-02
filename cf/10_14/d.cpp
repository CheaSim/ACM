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
char mx[maxn][maxn];
struct node{
    int a,b;
    int l,r;
    bool operator<(const node &x)const {
        return l+r<x.l+x.r;
    }
    node(){}
    node(int _a,int _b,int _l,int _r){
        a = _a;b = _b; l = _l; r = _r;
    }
};
int vis[maxn][maxn];
int stx,sty,m,n,l,r;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
void bfs(){
    priority_queue<node> pq;
    pq.push(node(stx,sty,l,r));
    while(!pq.empty()){
        node now = pq.top(); pq.pop();
        int x = now.a,y = now.b,l = now.l,r = now.r;
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        rep(i,0,4){
            int dx = x+dir[i][0],dy = y+dir[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m) continue;
            if(mx[dx][dy] == '*') continue;
            if(i==2 && r>0) pq.push(node(dx,dy,l,r-1));
            else if(i==3 && l>0) pq.push(node(dx,dy,l-1,r));
            else if(i<2)pq.push(node(dx,dy,l,r));
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d%d%d%d%d",&n,&m,&stx,&sty,&l,&r);
    stx--;sty--;
    rep(i,0,n){
        scanf("%s",mx[i]);
    }
    bfs();
    int ans = 0;
    rep(i,0,n) rep(j,0,m){
        if(vis[i][j]==1) ans++;
    }
    cout<<ans<<endl;


    return 0;
}
