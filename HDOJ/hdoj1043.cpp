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
char mx[4][4];
int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};
int vis[1<<15];
bool check(){
    rep(i,0,8){
        if(mx[i/3][i%3]!=i+1) return false;
    }
    return true;
}
int sta[1<<14];
int temp[1<<14],sss;
bool flag = 0;
void show(){
    rep(i,0,3){
        rep(j,0,3){
            printf("%c ",mx[i][j]+'0');
        }
        puts("");
    }
}
void dfs(int x,int y,int step){
    int cnt = 1;int pos = 0;
    rep(i,0,9){
        pos += (int)mx[i/3][i%3] *cnt;
        cnt<<=1;
    }
    if(check() && step<sss){
        flag = 1;
        rep(i,0,step) sta[i] = temp[i];
        sss = step;
        return;
    }
    if(vis[pos] <= step) return;
    vis[pos] = step;
    rep(i,0,4){
        int x1 = x+ dx[i];int y1 = y+ dy[i];
        if(x1<0 || x1>2 || y1<0 || y1>2) continue;
        mx[x][y] = mx[x1][y1];
        mx[x1][y1] = 0;
        temp[step] = i+1;
        dfs(x1,y1,step+1);
        mx[x1][y1] = mx[x][y];
        mx[x][y] = 0;
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(cin>>mx[0][0]){
        rep(i,0,(1<<15)) vis[i] = INF;
        sss = INF;
        flag = 0;
        rep(i,1,9){
            cin>>mx[i/3][i%3];
        }
        int xx,yy;
        rep(i,0,9){
            if(mx[i/3][i%3]!='x') mx[i/3][i%3] -= '0';
            else {mx[i/3][i%3] = 0;xx= i/3;yy=i%3;}
        }
        cout<<xx<<' '<<yy<<endl;
        dfs(xx,yy,0);
        if(flag){
            rep(i,0,sss){
                char ch;
                switch(sta[i]-1){
                    case 0:ch = 'u';break;
                    case 1:ch = 'r';break;
                    case 2:ch = 'd';break;
                    case 3:ch = 'l';break;
                }
                printf("%c",ch);
            }
            puts("");
        }else{
            puts("unsolvable");
        }

    }
    return 0;
}
