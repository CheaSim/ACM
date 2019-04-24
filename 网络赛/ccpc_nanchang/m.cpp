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
const int maxn = 1e5+10;
int dp[maxn][26];
int last[26];
char s[maxn],temp[1010];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%s",s);
    int n = strlen(s);
    memset(last,-1,sizeof(last));
    per(i,0,n){
        rep(j,0,26) dp[i][j] = last[j];
        last[s[i]-'a'] = i;
    }
    rep(i,0,26) dp[n][i] = last[i];
    int t; scanf("%d",&t);
    while(t--){
        scanf("%s",temp);
        int len = strlen(temp);
        int now = n;
        bool flag = false;
        if(len == 0 || len > n){
            puts("NO");
            continue;
        }
        rep(i,0,len){
            now = dp[now][temp[i]-'a'];
            if(now == -1){
                flag = true;
                break;
            }
        }
        if(flag) puts("NO");
        else puts("YES");
    }
    return 0;
}
