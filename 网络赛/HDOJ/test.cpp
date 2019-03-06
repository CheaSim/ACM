#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n = 1e6+10;
    ll temp = (ll)pow(n+1,3) - (ll)pow(n,3);
    cout<<(ll)pow(2,63)-1<<endl;
    cout<<(ll)pow(1e6,3)<<endl;
    cout<<(ll)pow(n+1ll,3) - (ll)pow(n,3)<<endl;
    cout<<(ll)pow(n+1ll,3) <<' '<<(ll)pow(n,3)<<endl;
    ll n_1 = n+1;
    cout<<n_1*n_1*n_1<<' '<<n*n*n<<endl;
    cout<<(ll)n_1*n_1*n_1 - n*n*n<<endl;
    ll temp1 = 3*n*n + 3*n + 1ll;
    cout<<temp1<<' ';
    return 0;
}
