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

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    string xx[10];
    string x;
    cin>>x;
    rep(i,0,5) cin>>xx[i];
    bool flag = false;
    rep(i,0,5){
        if(x[0] == xx[i][0] || x[1] == xx[i][1]) flag = true;
    }
    if(flag) puts("YES");
    else puts("NO");
    

    return 0;
}
