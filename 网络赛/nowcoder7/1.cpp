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
const int maxn = 5e5 + 5;
int ans[maxn];
void solve(int x){
    int b = 1;
    while(b <= x) b<<=1;
    int p = b-1-x;
    cout<<p<<endl;
    rep(i,p,x+1) ans[i] = b-1-i;
    if(p) solve(p-1);
}
int main(){
#ifdef LOCAL
   // freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    n--;
    solve(n);
    rep(i,0,n+1)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
