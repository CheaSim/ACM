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
const int maxn = 1e2+10;
int n,m;
set<int> st[maxn];
int vis[maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,m){
        int a,b; scanf("%d%d",&a,&b);
        st[a].insert(b);
        st[b].insert(a);
    }
    int ans = 0;
    rep(i,0,100){
        set<int> no;
        rep(j,1,n+1){
            if(vis[j]) continue;
            if(no.find(j) == no.end()){
                vis[j] = 1;
                for(set<int>::iterator it=st[j].begin();it != st[j].end();it++){
                    no.insert(*it);
                }
            }
        }
        int cnt = 0;
        rep(j,1,n+1) if(vis[j] ) cnt++;
        if(cnt==n){
            ans = i+1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
