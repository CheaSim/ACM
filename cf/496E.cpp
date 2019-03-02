#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 1e5+10;
struct node1{
    int l,r,id;
    int val;
    bool f = 0;
    bool operator<(const node1& x){
        if(l==x.l && r==x.r) return f==0;
        if(r==x.r) return l>x.l;
        return r<x.r;
    }
}a[maxn*2];
int res[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int n,m;scanf("%d",&n);
    rep(i,0,n){
        int x,y;scanf("%d%d",&x,&y);
        a[i].l = x; a[i].r = y;a[i].id = i;
    }
    scanf("%d",&m);
    rep(i,n,m+n){
        int x,y,val;scanf("%d%d%d",&x,&y,&val);
        a[i].l = x; a[i].r = y;a[i].val = val;
        a[i].id = i+1-n;a[i].f = 1;
    }
    sort(a,a+m+n);
    int ans = 0;
    set<pair<int,int> > s;
    rep(i,0,n+m){
        if(a[i].f==0) s.insert(mp(a[i].l,i));
        else{
            auto pos = s.lower_bound(mp(a[i].l,-1));
            while(pos!=s.end() && a[i].val){
                int x = pos->se; int y = pos->fi;
                a[i].val--;ans++; res[a[x].id] = a[i].id;
                s.erase(pos++);
            }
        }
    }
    if(ans == n){
        puts("YES");
        rep(i,0,n) printf("%d%c",res[i],i==n-1?'\n':' ');
    }else puts("NO");
    return 0;
}
