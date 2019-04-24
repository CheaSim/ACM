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
char num[maxn];
int len;
ll ans = 0;
void dfs(int step,ll now,int flag){
    if(step == len){
        ans = max(ans,now);
        return;
    }
    if(flag){
        dfs(step+1,now*max(1*num[step],1),flag);
        if(num[step] <= 1){
            dfs(step+1,now*1,0);
        }else{
            dfs(step+1,now*(num[step]-1),0);
        }
    }else{
        dfs(step+1,now*9,0);
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%s",num);
    len = strlen(num);
    rep(i,0,len) num[i] -= '0';
    dfs(0,1,1);
    printf("%lld\n",ans);
    return 0;
}
