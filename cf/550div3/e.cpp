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

const int maxn = 2e5+10;
char s[maxn];
char t[maxn];
char ans[maxn];
char temp[maxn];
int n;
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    int flag = 0;
    per(i,1,n+1){
        int tt = (s[i] + t[i] - 'a'*2 + flag);
        flag = 0;
        if(tt >= 26) flag = 1;
        temp[i] = (tt%26+'a');
    }
    int ttt = 1;
    if(flag) temp[0] = 'b';
    if(flag) ttt=0;
    flag = 0;
    rep(i,ttt,n+1){
        int tt = (temp[i] - 'a' + flag*26);
        flag = 0;
        if(tt%2==1) flag = 1;
        tt /=2;
        ans[i] = (tt+'a');
    }
    printf("%s",ans+1);
    return 0;
}
