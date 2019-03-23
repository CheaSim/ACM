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

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int a,b,c;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d%d",&a,&b,&c);
    int temp = 0;
    temp = a*b/gcd(a,b);
    temp = c*temp/gcd(c,temp);
    cout<<temp<<'\n';
    return 0;
}
