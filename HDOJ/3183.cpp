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
int m,n;
const int maxn = 1e3+10;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(gets(s)){
        int len = strlen(s);
        int cnt = len-2;
        while(s[cnt] <= '9' && s[cnt]>='0') cnt--;
        vector<int> a;
        rep(i,0,cnt){
            a.push_back(s[i]-'0');
        }
        a.push_back(0);
        sscanf(s+cnt,"%d",&m);
        rep(i,0,m){
            int id = 0,mmax = -1;
            int sz = a.size();
            rep(j,0,sz-1){
                if(a[j] > mmax && a[j]>a[j+1]){
                    mmax  = a[j];
                    id = j;
                    break;
                }
            }
            vector<int>::iterator it = a.begin();
            rep(j,0,id) it++;
            a.erase(it);
        }
        a.erase(--a.end());
        int sz = a.size();
        int x = 0;
        while(x<sz && a[x]==0) x++;
        rep(i,x,sz){
            printf("%d",a[i]);
        }
        if(sz==x) puts("0");
        else puts("");
    }
    return 0;
}
