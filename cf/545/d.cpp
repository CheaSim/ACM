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
const int maxn = 5e5+10;
char s[maxn],t[maxn];
int nxt[maxn];
void getnxt(char *str){
    int len = strlen(str);
    int i = 0, j = -1;
    nxt[0] = -1;
    while(i<len){
        if(j==-1 || str[i] == str[j]){
            i++,j++;
            nxt[i] = j;
        }else{
            j = nxt[j];
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%s",s); scanf("%s",t);
    getnxt(t);
    int len = strlen(t);
    int sz = 0;
    int cnt0 = 0,cnt1 = 0;
    int len1 = strlen(s);
    rep(i,0,len1){
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }
    int i = 0;
    bool flag = true;
    while(flag && cnt0 > 0 && cnt1 > 0){
        for(i;i<len;i++){
            if(t[i] == '1' && cnt1-- > 0) printf("1");
            else if(t[i] == '0' && cnt0-- > 0) printf("0");
            else {
                flag = false;break;
            }
        }
        i = nxt[len];
    }
    while(cnt0-->0) printf("0");
    while(cnt1-->0) printf("1");
    return 0;
}
