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
char s[30];
int len;
int vis[1<<18];
bool check(int x){
    char str[20] = "";int cnt = 0;
    rep(i,0,len){
        if(((x>>i)&1)==1)
            str[cnt++] = s[i];
    }
    rep(i,0,cnt/2){
        if(str[i] != str[cnt-i-1]) return false;
    }
    return true;
}
int Set[1<<18];
int tot;
int dfs(int S){
    if(vis[S]<INF) return vis[S];
    rep(i,0,tot) if((S&Set[i]) == Set[i]){
        vis[S] = min(dfs(S^Set[i]),vis[S]);
    }
    return ++vis[S];
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);len = strlen(s);
        tot = 0;
        int S = (1<<len) - 1;
        memset(vis,127,sizeof(vis));
        vis[0] = 0;
        rep(i,1,S+1){
            if(check(i)) Set[tot++] = i;
        }
        printf("%d\n",dfs(S));
    }

    return 0;
}
