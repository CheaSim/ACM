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

ll a,b,n;
vector<ll>ans;
int main(){
#ifdef LOCAL
    freopen("4.in","r",stdin);
#endif
    cin>>a>>b>>n;
    a = a%b;
    map<ll,int> mx;
    bool flag = false;
    while(a){
        if(mx[a] == 2) break;
        if(mx[a] == 1) flag = true;
        mx[a] ++;
        a = a*10;
        if(flag)
            ans.push_back(a/b);
        a -= a/b*b;
    }
    int len = ans.size();
    if(a==0){
        rep(i,n,n+3) cout<<ans[i];
    }else{
        rep(i,0,3) cout<<ans[(n+i+len-1)%len];
    }

    return 0;
}
