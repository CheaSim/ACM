#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
int n;
const int maxn = 3e5+10;
char s[maxn];
char temp[100];
void tochar(int x,char *t){
    int cnt = 0;
    rep(i,0,8) t[i] = '0';
    while(x){
        t[cnt++] = '0'+x%2;
        x /= 2;
    }
}
int bti(char *x){
    int res = 0;
    int cnt = 32;
    rep(i,0,6){
        res += cnt*(x[i]-'0');
        cnt/=2;
    }
    return res;
}
int main(){
    scanf("%s",s);
    n = strlen(s)/3;
    vector<int> ans;
    rep(i,0,n){
        tochar(s[i*3],temp);
        tochar(s[i*3+1],temp+8);
        tochar(s[i*3+2],temp+16);
        ans.push_back(bti(temp));
        ans.push_back(bti(temp+6));
        ans.push_back(bti(temp+12));
        ans.push_back(bti(temp+18));
    }
    int sz = ans.size();
    for(int i=0;i<sz;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
