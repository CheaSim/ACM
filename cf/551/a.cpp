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
const int maxn = 1e5+10;
int n,t;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&t);
    int ans = 0;
    int mmin = INF;
    rep(i,0,n){
        int s,d; scanf("%d%d",&s,&d);
        s += max(0,t-s)/d*d;
        if(s<t) s+=d;
        if(s-t < mmin){
            ans = i+1;
            mmin = s-t;
        }
    }
    printf("%d\n",ans);
    return 0;
}
