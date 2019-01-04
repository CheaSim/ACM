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
int n,m,k;
const int maxn = 1e5 + 10;
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    while(~scanf("%d%d%d",&n,&m,&k)){
        rep(i,1,n+1) scanf("%d",&a[i]);
        deque<int> dq1; //min
        deque<int> dq2; //max
        int ans = 0;int pos = 0;
        rep(i,1,n+1){
            while(!dq1.empty() && a[dq1.back()]>=a[i]) dq1.pop_back();
            dq1.push_back(i);
            while(!dq2.empty() && a[dq2.back()]<=a[i]) dq2.pop_back();
            dq2.push_back(i);
            while(!dq1.empty() && !dq2.empty() && a[dq2.front()]-a[dq1.front()]>k){
                if(dq1.front() < dq2.front())
                    pos = dq1.front(),dq1.pop_front();
                else
                    pos = dq2.front(),dq2.pop_front();
            }
            if(!dq1.empty() && !dq2.empty() && a[dq2.front()]-a[dq1.front()] >=m)
                ans = max(ans,i-pos);
        }
        printf("%d\n",ans);
    }
    return 0;
}
