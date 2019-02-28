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
const int maxn = 1e3+10;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int n;scanf("%d",&n);
    rep(i,0,n){
        cin>>a[i];
    }
    int ans = INF;
    int res = 0;
    rep(i,1,101){
        int temp = 0;
        rep(j,0,n){
            if(a[j] < i-1){
                temp += i-1-a[j];
            }
            if(a[j] > i+1){
                temp += a[j]-i-1;
            }
        }
        if(ans > temp){
            ans = temp;
            res = i;
        }
    }
    cout<<res<<' '<<ans<<'\n';


    return 0;
}  
