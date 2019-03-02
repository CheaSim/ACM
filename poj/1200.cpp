#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
typedef unsigned long long ull;
const int maxn = 16e6+10;
ull hush[265];
ull bas = 31;
int n,nc;
char s[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&nc)){
        scanf("%s",s);int len = strlen(s);
        memset(vis,0,sizeof(vis));
        memset(hush,0,sizeof(hush));
        int cnt = 1;
        rep(i,0,len){
            if(hush[s[i]]==0) hush[s[i]] = cnt++;
        }
        int ans = 0;
        for(int i=0;i+n<=len;i++){
            ull sum = 0;
            rep(j,i,i+n){
                sum *= nc;
                sum += hush[s[j]];
            }
            if(vis[sum]==0){
                vis[sum] = 1;
                ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
