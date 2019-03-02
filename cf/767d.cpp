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
int n,m,k;
const int maxn = 1e6+10;
const int maxm = 1e7+10;
int vis[maxm];
int mx[maxm];
struct node{
    int id;
    int val;
    bool operator<(const node &x)const{
        return val>x.val;
    }
}a[maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    bool flag = false;
    rep(i,0,n){
        int x;scanf("%d",&x);
        vis[x]++;
    }
    rep(i,0,m){
        int x;scanf("%d",&x);
        mx[x]++;
        a[i].val = x; a[i].id = i+1;
    }
    sort(a,a+m);
    int ans = 0;
    ll  now = k;
    rep(i,0,maxm){
        if(vis[i] > now){
            flag = true;
            break;
        }else{
            int temp = min(now-vis[i],(ll)mx[i]);
            int t = vis[i] + temp;
            ans += temp;
            now += k-t;
        }
    }
    if(flag) puts("-1");
    else{
        printf("%d\n",ans);
        rep(i,0,ans){
            printf("%d ",a[i].id);
        }
        puts("");
    }
    
    return 0;
}
