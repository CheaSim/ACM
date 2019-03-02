#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
int read() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
#define id(x,y) (x-1)*m+y
const int maxn = 1e6 + 1000;
int n,m,T;
int ans[maxn];
int s[maxn],x1[maxn],x2[maxn],y1[maxn],y2[maxn],kind[maxn],a[maxn];
void add(int k,int *f){
    int a,b,c,d;
    a=x1[k]; b=x2[k]; c=y1[k]; d=y2[k];
    f[id(a,c)]++;
    if(b<n) f[id(b+1,c)]--;
    if(d<m) f[id(a,d+1)]--;
    if(b<n&&d<m) f[id(b+1,d+1)]++;
}
void gen(int *f){
    rep(i,1,n+1) rep(j,1,m+1){
        if(i>1) f[id(i,j)] += f[id(i-1,j)];
        if(j>1) f[id(i,j)] += f[id(i,j-1)];
        if(i>1&&j>1) f[id(i,j)] -= f[id(i-1,j-1)];
    }
}
int main(){
#ifdef LOCAL
    freopen("j.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&T);
    rep(i,1,n+1) rep(j,1,m+1) a[id(i,j)] = read();
    rep(i,0,T){
        x1[i]=read();y1[i]=read();x2[i]=read();y2[i]=read();kind[i]=read();
        add(i,s);
    }
    gen(s);
    rep(bit,0,21){
        int f[maxn] ={0};
        rep(i,0,T){
            if(kind[i]>>bit & 1){
                add(i,f);
            }
        }
        gen(f);
        rep(i,1,n+1) rep(j,1,m+1){
            if(a[i]>>bit & 1){
                if(f[id(i,j)]!=s[id(i,j)])
                    ans[id(i,j)] = 1;
            }else if(f[id(i,j)]){
                ans[id(i,j)] = 1;
            }
        }
    }
    int res = 0;
    rep(i,1,n+1) rep(j,1,m+1){
        if(ans[id(i,j)]) res++;
    }
    printf("%d\n",res);
    return 0;
}
