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
const int maxn = 3e5+10;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d",&n);
    scanf("%s",s);
    bool flag = false;
    int cnt1 = 0;
    int cnt2 = 0;
    rep(i,0,n){
        if(s[i] == '(') cnt1++;
        if(s[i] == ')') cnt2++;
    }
    if(n%2) flag = true;
    if(cnt1 > n/2 || cnt2 > n/2) flag = true;
    int left = n/2 - cnt2;
    per(i,0,n){
        if(left > 0 && s[i] == '?'){
            left--;
            s[i] = ')';
        }
    }
    rep(i,0,n) if(s[i] == '?') s[i] = '(';
    int cnt = 0;
    rep(i,0,n-1){
        if(s[i] == '(') cnt++;
        if(s[i] == ')') cnt--;
        if(i!=0 && cnt==0) flag = true;
        if(cnt<0) flag = true;
    }
    if(flag) puts(":(");
    else printf("%s",s);

    return 0;
}
