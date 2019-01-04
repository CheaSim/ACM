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
const int maxn = 1e5 + 10;
char s[maxn];
int vis[26];
int n;
int main(){
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    scanf("%d",&n);
    scanf("%s",s);
    if(n==1){
        puts("Yes");
        return 0;
    }
    rep(i,0,n){
        vis[s[i]-'a']++;
        if(vis[s[i]-'a'] > 1){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
