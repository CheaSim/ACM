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
int n,m;
bool vis[100];
int query(int x){
    int y;
    cout<<x<<endl;
    fflush(stdout);
    cin>>y;
    return y;
}
int main(){
#ifdef LOCAL
    //freopen("4.in","r",stdin);
#endif
    scanf("%d%d",&m,&n);
    rep(i,0,n){
        int x = query(1);
        if(x == 0){
            cout<<1<<endl;
            return 0;
        }
        if(x<0) vis[i] = 1;
    }
    int mid = 0;int cnt = 0;
    int l,r;
    l = 1,r = m;
    while(l<=r){
        mid = (l+r)>>1;
        int y = query(mid);
        if(vis[cnt]) y = -y;
        if(y==1) l = mid+1;
        else if(y==-1)r = mid-1;
        else{
            cout<<mid<<endl;
            return 0;
        }
        cnt = (cnt+1)%n;
    }
    return 0;
}
