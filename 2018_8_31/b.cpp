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
int m,n;
const int maxn = 110;
int a[maxn],b[maxn];
bool cmp(int a,int b){
    return a>b;
}
int cnt,ans;
void dfs(int day,int idx,int p){
    if(p <= 0){
        ans = max(ans,day);
        return;
    }
    if(idx ==cnt) return;
    for(int i=1;i<=a[idx];i++){
        if(a[idx] / i < day) continue;
        dfs(day,idx+1,p-i);
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,1,m+1){
        int x;scanf("%d",&x);
        a[x]++;
    }
    ans = 0;
    sort(a+1,a+m+1,cmp);
    rep(i,1,101) if(a[i]==0) {cnt = i;break;}
    for(ans = 1;ans<=100;ans++){
        int peo = 0;
        rep(i,1,10){
            peo += a[i]/ans;
        }
        if(peo <n){
            break;
        }
    }
    printf("%d\n",ans-1);
    return 0;
}
