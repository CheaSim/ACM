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
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        ll l,r,d;
        cin>>l>>r>>d;
        if(d<l){
            cout<<d<<'\n';
        }else{
            cout<< r/d*d+d<<'\n';
        }
    }


    return 0;
}
