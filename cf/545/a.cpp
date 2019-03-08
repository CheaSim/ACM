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
const int maxn = 1e5+10;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    vector<int> ve;
    int n; scanf("%d",&n);
    int cnt1 = 0,cnt2 = 0;
    int ans = 0;
    rep(i,0,n) scanf("%d",a+i);
    int cnt = 0;
    while(cnt<n){
        cnt1= 0;
        cnt2 = 0;
        while(a[cnt] == 1){
            cnt++;
            cnt1++;
        }
        ve.push_back(cnt1);
        while(a[cnt] == 2){
            cnt++;
            cnt2++;
        }
        ve.push_back(cnt2);
    }
    int len = ve.size();
    rep(i,0,len-1){
        ans = max(ans,2*min(ve[i],ve[i+1]));
    }
    printf("%d\n",ans);
    return 0;
}
