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
bool ans = false;
int n;
int a[maxn];
void dfs(int res,int step){
    res = res % 360;
    if(res == 0 && step==n) {
        ans = true;
        return;
    }
    if(ans) return;
    if(step == n) return;
    dfs(res+a[step],step+1);
    dfs(res-a[step],step+1);
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep(i,0,n) cin>>a[i];
    dfs(0,0);
    if(ans) puts("YES");
    else puts("NO");
    return 0;
}
