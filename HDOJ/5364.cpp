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
const int maxn = 1e3+10;
int n;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(~scanf("%d",&n)){
        map<int,int>mx;
        int ans = -1;
        rep(i,0,n){
            int x; scanf("%d",&x);
            mx[x]++;
            if(mx[x]>n/2) ans = x;
        }
        if(ans!=-1)
            printf("%d\n",ans);
        else puts("-1");
    }

    return 0;
}
