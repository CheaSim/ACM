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
int vis[30];
int ans[30];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int n,k; scanf("%d%d",&n,&k);
    scanf("%s",s);
    int len = strlen(s);
    vis[s[0]-'a'] ++;
    int res = 0;
    rep(i,0,26) if(vis[i]==k) ans[i]++; 
    bool flag = true;
    rep(i,1,n){
        vis[s[i]-'a']++;
        if(i-k>=0 && flag) vis[s[i-k]-'a']--;
        if(!flag){
            rep(j,i-k+1,i) vis[s[j]-'a']++;
        }
        flag = true;
        rep(j,0,26){
            if(vis[j]==k){
                i+=k-1;
                ans[j]++;
                vis[j]=0;
                flag = false;
            }
        }
    }
    rep(i,0,26) res = max(res,ans[i]);
    cout<<res<<'\n';
    return 0;
}
