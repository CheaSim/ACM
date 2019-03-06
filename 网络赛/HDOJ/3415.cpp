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
int T,n,k;
const int maxn = 1e5 + 123;
int a[maxn*3];
int b[maxn];
int main(){
#ifdef LOCAL
    freopen("11.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        rep(i,0,n) scanf("%d",&b[i]);
        rep(i,1,n*2+1) a[i] = (a[i-1] + b[(i-1)%n]);
        deque<int> dq;
        int ans = -INF;
        int l,r;
        rep(i,1,2*n+1){
            while(!dq.empty() && i-dq.front() > k) dq.pop_front();
            while(!dq.empty() && a[dq.back()] > a[i-1]) dq.pop_back();
            dq.push_back(i-1);
            int temp = a[i] - a[dq.front()];
            if(ans < temp){
                ans = temp;
                l = dq.front()+1; r = i;
                if(r>n) r-=n;
            }
        }
        printf("%d %d %d\n",ans,l,r);
    }
    return 0;
}
