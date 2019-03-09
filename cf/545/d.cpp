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
    bool flag = false;
    int len = strlen(t);
    int sz = 0;
    if(len%(len-1 - nxt[len-1])==0) {
        flag = 1;
        sz = len/(len-1 - nxt[len-1]);
    }
    int cnt0 = 0,cnt1 = 0;
    int len1 = strlen(s);
    rep(i,0,len1){
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }
    if(!flag){
        int len = strlen(t);
        int t1=0,t2=0;
        rep(i,0,len) if(t[i] == '1') t1++; else t2++;
        cnt0 -= t1;
        cnt1 -= t2;
        if(cnt0 < 0 || cnt1 < 0){
            printf("%s",s);
        }else{
            printf("%s",t);
            while(cnt0-->0) printf("0");
            while(cnt1-->0) printf("1");
        }
        return 0;
    }
    vector<char>ans;
    vector<char> cir;
    int ned0 = 0, ned1 = 0;
    rep(i,0,sz){
        cir.push_back(t[i]);
        if(t[i] == '1') ned1++;
        else ned0++;
    }
    if(ned0 == 0) ned0 = INF;
    if(ned1 == 0) ned1 = INF;
    int times = min(cnt0/ned0,cnt1/ned1);
    rep(i,0,times){
        for(auto &x:cir) printf("%c",x);
    } 
    cnt0 -= times*ned0;
    cnt1 -= times*cnt1;
    while(cnt0-->0) printf("0");
    while(cnt1-->0) printf("1");
    return 0;
}
