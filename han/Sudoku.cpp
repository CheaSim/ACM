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
const int maxn = 20;
int row[maxn][maxn];
int col[maxn][maxn];
int block[maxn][maxn];
vector<pair<int,int> > state;
int n;
int ans[maxn][maxn];
int res = 0;
void dfs(int step){
    if(res) return;
    if(step==n){
        rep(i,0,9) rep(j,0,9){
            printf("%d%c",ans[i][j],j==8?'\n':' ');
        }
        res = 1;
        return;
    }
    int x = state[step].fi;
    int y = state[step].se;
    rep(i,1,10){
        if(row[x][i]) continue;
        if(col[y][i]) continue;
        if(block[x/3*3+y/3][i]) continue;
        row[x][i] = 1;
        col[y][i] = 1;
        block[x/3*3+y/3][i] = 1;
        ans[x][y] = i;
        dfs(step+1);
        row[x][i] = 0;
        col[y][i] = 0;
        block[x/3*3+y/3][i] = 0;
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    int f = 1;
    while(cin>>ch){
        res = 0;
        if(!f) puts("");
        f=0;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(block,0,sizeof(block));
        memset(ans,0,sizeof(ans));
        state.clear();
        if(ch=='?'){
            state.push_back(make_pair(0,0));
        }else{
            row[0][ch-'0'] = 1;
            col[0][ch-'0'] = 1;
            block[0][ch-'0'] = 1;
            ans[0][0] = ch - '0';
        }
        rep(i,0,9) rep(j,i==0?1:0,9){
            cin>>ch;
            if(ch=='?'){
                state.push_back(make_pair(i,j));
            }else{
                row[i][ch-'0'] = 1;
                col[j][ch-'0'] = 1;
                block[i/3*3+j/3][ch-'0'] = 1;
                ans[i][j] = ch - '0';
            }
        }
        n = state.size();
        dfs(0);
    }
    return 0;
}
 
