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

int n,m;
const int maxn = 3e5+10;
int idx[maxn];
set<int> st[maxn];
int a[maxn];
int vis[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        int x; scanf("%d",&x);
        a[i] = x; idx[x] = i;
    }
    rep(i,0,m){
        int x,y; scanf("%d%d",&x,&y);
        st[x].insert(y);
        if(y == a[n]) vis[x] = 1;
    }
    per(i,1,n-1){
        if(vis[a[i]] == 0) continue;
        int t = i;
        while(t<n-1 && st[a[t]].find(a[t+1]) != st[a[t]].end()){
            swap(a[t],a[t+1]);
            t++;
        }
    }
    int ans = 0;
    per(i,1,n){
        if(vis[a[i]] == 0) break;
        ans++;
    }
    printf("%d",ans);
    return 0;
}
