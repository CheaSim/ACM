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
const int maxn = 2e5+10;
int a[maxn];
int vis[3];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a+i),vis[a[i]]++;
    rep(i,0,n){
        vis[a[i]]--;
        if(vis[a[i]] == 0) {
            printf("%d\n",i+1);
            break;
        }
    }
    return 0;
}
