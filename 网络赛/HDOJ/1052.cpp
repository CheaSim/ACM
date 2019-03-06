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
int n, ans;
const int maxn = 1e3 + 5;
int king[maxn],tian[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
#ifdef LOCAL
    freopen("1052.in","r",stdin);
#endif
    while(scanf("%d",&n) && n){
        ans = 0;
        rep(i,0,n) scanf("%d",&tian[i]);
        rep(i,0,n) scanf("%d",&king[i]);
        sort(tian,tian+n,cmp);sort(king,king+n,cmp);
        int kl,kr,tl,tr;
        kl = tl = 0;
        kr = tr = n-1;
        while(kl<=kr){
            if(king[kl] < tian[tl]){
                ans++; kl++; tl++;
            }else if(king[kl] == tian[tl]){
                if(king[kr] >= tian[tr]){
                    if(king[kl] == tian[tr]){
                        kl++; tr--;
                    }else if(king[kl] > tian[tr]){
                        ans--;kl++;tr--;
                    }
                }else{
                    ans++;
                    tr--;
                    kr--;
                }
            }else{
                ans--;kl++;tr--;
            }
        }
        printf("%d\n",ans*200);
    }
    return 0;
}
