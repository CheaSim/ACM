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
int n;
const int maxn = 1e6+100;
char s[maxn];
int vis[3*maxn];
bool solve(){
    if(s[0]!='M') return false;
    int t = 0;
    int len = strlen(s);
    rep(i,1,len){
        if(s[i]=='M') return false;
        if(s[i]=='U') t += 3;
        else t ++;
    }
    if(vis[t]) return true;
    else return false;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=0;pow(2,i)<maxn;i++){
        int x = pow(2,i);
        while(x>0){
            vis[x] = 1;
            x -= 6;
        }
    }
    while(n--){
        scanf("%s",s);
        if(solve()){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}
