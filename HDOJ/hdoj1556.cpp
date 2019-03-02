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
const int maxn = 1e5 + 10;
int bit[maxn];
int lowbit(int x){return x&-x;}
void update(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        bit[i] += val;
    }
}
int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)){
        res += bit[i];
    }
    return res;
}
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    while(scanf("%d",&n) && n){
        memset(bit,0,sizeof(int)*(n+1));
        rep(i,0,n){
            int a,b;scanf("%d%d",&a,&b);
            update(a,1);update(b+1,-1);
        }
        rep(i,1,n+1){
            printf("%d%c",sum(i),i==n?'\n':' ');
        }
    }
    return 0;
}
