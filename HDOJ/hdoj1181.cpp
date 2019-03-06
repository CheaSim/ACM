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
const int maxn = 100;
int mx[30][30];
char s[maxn];
int res = 0;
int vis[maxn];
void dfs(int x){
    if(res) return;
    if(x == 'm'-'a'){
        res = 1;
        return;
    }
    if(vis[x]) return;
    vis[x] = 1;
    rep(i,0,26){
        if(mx[x][i]){
            dfs(i);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(cin>>s){
        if(s[0] == '0'){
            dfs('b'-'a');
            if(res) puts("Yes.");
            else puts("No.");
            memset(mx,0,sizeof(mx));
            res = 0;
            continue;
        }
        int len = strlen(s);
        mx[s[0]-'a'][s[len-1]-'a'] = 1;
    }
    return 0;
}
