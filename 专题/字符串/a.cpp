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
typedef unsigned long long ull;
const int maxn = 1e5+10;
ull xp[maxn],Hash[maxn];
void init(){
    xp[0] = 1;
    rep(i,1,maxn) xp[i] = xp[i-1] * 175;
}
ull get_Hash(int i,int L){
    return Hash[i] - Hash[i+L] * xp[L];
}
int n,m;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    init();
    // m = length of L
    while(~scanf("%d%d",&n,&m)){
        scanf("%s",s);
        int len = strlen(s);
        Hash[len] = 0;
        per(i,0,len){
            Hash[i] = Hash[i+1]*175+(s[i]-'a'+1);
        }
        int ans = 0;
        for(int i=0;i<m && i<=len-m*n;i++){
            map<ull,int> mx;
            for(int j=i;j<i+m*n;j+=m){
                ull temp = get_Hash(j,m);
                mx[temp] ++;
            }
            if(mx.size() == n) ans++;
            for(int j = i+n*m;j+m<=len;j+=m){
                ull temp = get_Hash(j-n*m,m);
                mx[temp]--;
                if(mx[temp] == 0) mx.erase(temp);
                temp = get_Hash(j,m);
                mx[temp]++;
                if(mx.size() == n) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
