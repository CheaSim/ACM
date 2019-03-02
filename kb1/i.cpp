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
const int maxn = 5e4+20;
int bit[maxn];
int lowbit(int x){
    return x&-x;
}
int query(int x){
    int ans = 0;
    for(int i = x;i;i-=lowbit(i)){
        ans += bit[i];
    }
    return ans;
}
int query(int l,int r){
    return query(r)-query(l-1);
}
void add(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        bit[i] += val;
    }
}
int solve_left(int l,int r){
    int mid = l+r>>1;int ans = r;
    while(l<=r){
        mid = l+r>>1;
        if(query(mid,r)==r-mid+1) r = mid-1,ans = mid;
        else l = mid+1;
    }
    return ans;
}
int solve_right(int l,int r){
    int mid,ans = l;
    while(l<=r){
        mid = l+r>>1;
        if(query(l,mid)==mid-l+1) l=mid+1,ans = mid;
        else r = mid-1;
    }
    return ans;
}
int vis[maxn];
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)!=EOF){
        stack<int> st;
        memset(bit,0,sizeof(bit));
        memset(vis,0,sizeof(vis));
        rep(i,1,n+1) add(i,1);
        while(m--){
            char op[20];scanf("%s",op);
            if(op[0]=='D'){
                int x;scanf("%d",&x);
                st.push(x);
                if(vis[x]) continue;
                vis[x] = 1;
                add(x,-1);
            }else if(op[0]=='Q'){
                int x;scanf("%d",&x);
                if(query(x,x)==0) puts("0");
                else printf("%d\n",solve_right(x,n)-solve_left(1,x)+1);
            }else{
                add(st.top(),1);
                vis[st.top()] = 0;
                st.pop();
            }
        }
    }

    return 0;
}
