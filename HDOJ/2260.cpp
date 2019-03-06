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

ll n,m;
const int maxn = 30;
ll num[maxn];
vector<int> ve;
ll ans = INT_MAX;
int tans[maxn];
int temp[maxn];
void dfs(int x,ll now){
    if(abs(now-m) < ans && x == n){
        ans = abs(now-m);
        memcpy(tans,temp,sizeof(temp));
    }
    ll tt = 0;
    if(now-m > ans) return;
    rep(i,x,n) tt += num[ve[i]];
    if(tt + now + ans < m ) return ;
    if(x==n) {
        return ;
    }
    temp[ve[x]] = 1;
    dfs(x+1,now + num[ve[x]]);
    temp[ve[x]] = 0;
    dfs(x+1,now);
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(cin>>n>>m){
        ve.clear();
        memset(temp,0,sizeof(temp));
        memset(tans,0,sizeof(tans));
        rep(i,0,n){
            ll x; char ch; cin>>ch>>x;
            ve.push_back(ch-'A');
            num[ch-'A'] = x;
        }
        sort(ve.begin(),ve.end());
        ans = INT_MAX;
        dfs(0,0);
        vector<int> reans;
        rep(i,0,26) if(tans[i]) reans.push_back(i+'A');
        int len = reans.size();
        printf("%d\n",len);
        rep(i,0,len){
            printf("%c%c",reans[i],i==len-1?'\n':' ');
        }
    }
    return 0;
}
