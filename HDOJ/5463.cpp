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
const int maxn = 1e3+10;
int vis[maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        map<int,int>mx;
        int cnt = 0;
        scanf("%d",&n);
        rep(i,0,n){
            int a,b; scanf("%d%d",&a,&b);
            mx[a]+=b;
        }
        rep(i,1,500+1){
            int t = mx[i];
            int temp = t/64;
            if(temp*64<t) temp++;
            cnt += temp;
        }
        int ans = cnt/36;
        if(36*ans<cnt) ans++;
        printf("%d\n",ans);
    }

    return 0;
}
