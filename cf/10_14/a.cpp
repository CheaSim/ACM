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

int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b<c) swap(b,c);
    if(a+b>c && a-b<c) puts("0");
    else{
        int ans = abs(a+b-c)+1;
        ans = min(ans,abs(b+c-a)+1);
        printf("%d",ans);
    }
    return 0;
}
