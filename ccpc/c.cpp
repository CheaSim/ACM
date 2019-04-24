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
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",n-1+(n-1)*n/2);
    }
    return 0;
}
