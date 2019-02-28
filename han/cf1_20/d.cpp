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
int n,m,p;
const int maxn = 1e3+10;
int s[10];
char mx[maxn][maxn];
vector<pair<int,int> >st[20];
struct node{
    int x,y,num;
    node(){}
    node(int a,int b,int c){
        x = a;
        y = b;
        num = c;
    }
};
int ans[20];
int dir[4][2] = {0,1, 0,-1, 1,0, -1,0};
queue<node>q;
void bfs1(int x,int y,int step,int index){
    queue<node>qe;
    qe.push(node(x,y,0));
    while(!qe.empty()){
        node now = qe.front(); qe.pop();
        if(now.num >= step) continue;
        rep(i,0,4){
            int xx = now.x + dir[i][0];
            int yy = now.y + dir[i][1];
            if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if(mx[xx][yy] != '.') continue;
            mx[xx][yy] = index + '0';
            q.push(node(xx,yy,index));
            ans[index]++;
            qe.push(node(xx,yy,now.num+1));
        }  
    }

}
void bfs(){
    rep(i,1,p+1){
        int len = st[i].size();
        rep(j,0,len){
            q.push(node(st[i][j].fi,st[i][j].se,i));
        }
    }
    while(!q.empty()){
        node now = q.front(); q.pop();
        int num = now.num;
        bfs1(now.x,now.y,s[num],num);
    }
}
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&p);
    rep(i,1,p+1) cin>>s[i];
    rep(i,0,n){
        scanf("%s",mx[i]);
        rep(j,0,m){
            if(mx[i][j]!='.' && mx[i][j]!='#'){
                st[mx[i][j]-'0'].push_back(make_pair(i,j));
                ans[mx[i][j]-'0'] ++;
            }
        }
    }
    bfs();

    rep(i,1,p+1) cout<<ans[i]<<' ';
    

    return 0;
}  
