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
inline int read(){
    int x = 0;
    char c = getchar();
    bool flag = 0;
    while(c<'0' || c>'9'){ if(c=='-') flag=1; c = getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0'; c = getchar();}
    return flag?-x:x;
}
const int maxn = 1<<17;
ll bit[maxn];
vector<int< G[maxn],sp[maxn],large;
int dep[maxn],in[maxn],out[maxn],clk,n;
inline int lowbit(int x){
    return x&-x;
}
ll query(int x){
    ll res = 0;
    for(int i=x;i;i-=lowbit(i)){
        res += bit[i];
    }
    return res;
}
void update(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        bit[x] += val;
    }
}
void init(){
    rep(i,0,n+1) bit[i] = 0;
}
const int B = 1<<10;
int main(){ 
#ifdef LOCAL
    freopen("j.in","r",stdin);
#endif
    return 0;
}  
