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
int n,m;
int a[maxn],b[maxn];
char s[maxn];
int len;
bool solve(int x){
    int cnt = 0;
    int i = 0;
    int last = 0;
    while(cnt<m){
        if(s[i] % x == 0){
            b[cnt++] = s[i]/x;
        }else{
            if(s[i]>=x) return false;
            last = s[i]*10 + s[++i];
            if(last % x) return false;
            b[cnt++] = last/x;
        }
        i++;
    }
    cnt = 0;
    int now = 0;
    rep(i,0,len){
        int cmp = b[cnt];
        if(cnt==0){
            if(s[i] % cmp){
                if(s[i] >= cmp) return false;
                last = s[i]*10 + s[++i];
                if(last % b[cnt]) return false;
                a[now++] = last/b[cnt];
            }else{
                a[now++] = s[i]/cmp;
            }
        }else{
            if(cmp*a[now-1]>=10){
                last = s[i]*10 + s[++i];
                if(cmp*a[now-1] != last) return false;
            }else{
                last = s[i];
                if(cmp*a[now-1] != last) return false;
            }
        }
        cnt++;
        if(now==n && cnt==m && i==len-1) return true;
        if(cnt==m) cnt = 0;
    }
    return false;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        scanf("%s",s);
        len = strlen(s);
        rep(i,0,len) s[i] -= '0';
        bool flag = false;
        rep(i,1,10){
            if(solve(i)){
                flag = true;
                break;
            }
        }
        if(!flag){
            puts("Impossible");
            continue;
        }
        rep(i,0,n) printf("%d",a[i]);
        printf(" ");
        rep(i,0,m) printf("%d",b[i]);
        puts("");
    }
    return 0;
}
