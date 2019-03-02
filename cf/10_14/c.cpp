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
const int maxn = 1e5+100;
char s[maxn];
int vis[30];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int n;
    cin>>n;scanf("%s",s);
    rep(i,0,n){
        vis[s[i]-'a'] ++;
    }
    rep(i,0,26){
        while(vis[i]){
            cout<<(char)(i+'a');
            vis[i]--;
        }
    }
    return 0;
}
