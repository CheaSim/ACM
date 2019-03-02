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
int n,k;
const int maxn = 1e4+100;
char s[maxn];
int ve[maxn];
int solve(){
    bool flag = 0;
    int cnt = 0;
    int l = 0,r = 0;
    int ans = 0;
    int j = 0;
    int st = 0,ed = n-1;
    per(i,0,n){
        if(s[i]==1) r++;
        if(s[i]==0) break;
        s[i] = 0;
    }
    while(s[st]==1&&st<n) st++;
    l = st;
    rep(i,st,n){
        if(s[i] == 1) cnt++;
        if(s[i] == 0 && cnt){
            ve[++j] = cnt;
            cnt = 0;
        }
    }
    if(k==0) return l;
    sort(ve+1,ve+j+1);
    while(k>2 && j>=1){
        ans += ve[j--];
        k-=2;
    }
    if(k==1){
        ans += max(l+r,ve[j]);
    }else{
        ans += max(l+r,max(l+ve[j],r+ve[j]));
    }
    return ans;
}
char temp[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&k)){
        scanf("%s",s);
        rep(i,0,n) s[i] -= '0';
        printf("%d\n",solve());
    }

    return 0;
}
