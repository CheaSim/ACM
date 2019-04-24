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

const int maxn = 1e2+10;
int n;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s);
        int ans = INF;
        int cnt = 0;
        while(s[cnt] != '>' && cnt<n) cnt++;
        ans = cnt;
        cnt = n-1;
        while(s[cnt] != '<' && cnt>=0) cnt--;
        ans = min(ans,n-cnt-1);
        printf("%d\n",ans);
    }
    return 0;
}
