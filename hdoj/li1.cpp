#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
const int maxn = 1e4 + 10;
int n,ans;
int a[maxn];
int T;
int main(){
#ifdef LOCAL
    freopen("111.in","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&a[i]);
    }
    deque<int> dq1;
    deque<int> dq2;
    sort(a,a+n);
    rep(i,0,n) dq1.pb(a[i]);
    ans = 0;
    int x,y;
    rep(i,0,n-1){
        if(dq2.empty()){
            x = dq1.front();
            dq1.pop_front();
        }else if(dq1.empty()){
            x = dq2.front();
            dq2.pop_front();
        }else{
            if(dq1.front() < dq2.front()){
                x = dq1.front(),dq1.pop_front();
            }else{
                x = dq2.front(),dq2.pop_front();
            }
        }
        if(dq2.empty()){
            y = dq1.front();
            dq1.pop_front();
        }else if(dq1.empty()){
            y = dq2.front();
            dq2.pop_front();
        }else{
            if(dq1.front() < dq2.front()){
                y = dq1.front(),dq1.pop_front();
            }else{
                y = dq2.front(),dq2.pop_front();
            }
        }
        ans += (x+y);
        dq2.pb(x+y);
    }
    printf("%d\n",ans);
    return 0;
}
