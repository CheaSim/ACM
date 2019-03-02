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
ull base[maxn],pos[maxn],has[maxn];
ull bas = 31;
map<ull,int> hash_table;
int n,m;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    base[0] = 1;
    rep(i,1,maxn) base[i] = base[i-1]*bas;
    pos[0] = 0;
    while(~scanf("%d%d",&n,&m)){
        scanf("%s",s); int len = strlen(s);
        per(i,0,len) has[i] = has[i+1]*bas+s[i]-'a'+1;
        int ans = 0;
        for(int i=0;i<m&&i+n*m<len;i++){
            hash_table.clear();
            for(int j=i;j<i+n*m;j+=m){
                hash_table[has[j]-has[j+m]*base[m]]++;
            }
            ans += hash_table.size() == n;
            for(int j=i+n*m;j+m<=len;j+=m){
                ull temp = has[j-n*m] - has[j-(n-1)*m]*base[m];
                hash_table[temp] -- ;
                if(hash_table[temp]==0) hash_table.erase(temp);
                temp = has[j] - has[j+m]*base[m];
                hash_table[temp] ++;
                ans += hash_table.size() == n;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
