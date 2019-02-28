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

const int maxn = 1e5+10;
struct node{
    int l,r;
    bool operator<(const node& x)const{
        if(l==x.l) return r<x.r;
        return l<x.l;
    }
    node(){}
    node(int x,int y){
        l = x;
        r = y;
    }
}k[maxn];

char s[maxn*5];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int n;
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    map<node,ll> mp;
    ll cnt = 0;
    rep(i,0,n){
        cin>>s;
        int len = strlen(s);
        int l = 0 ,r = 0;
        rep(j,0,len){
            if(s[j] == '('){
                l++;
            }
            if(s[j] == ')'){
                if(l) l--;
                else r++;
            }
        }
        k[i].l = l;
        k[i].r = r;
        if(l==0 && r==0){
            cnt++;
            continue;
        }
        mp[node(l,r)] ++;
    }
    ll ans = 0;
    ans += cnt/2;
    rep(i,0,n){
        if(k[i].r == 0 && k[i].l) {
            if(mp[node(0,k[i].l)]) ans++;
            mp[node(0,k[i].l)] --;
            mp[node(k[i].l,k[i].r)]--;
        }
        if(k[i].l == 0 && k[i].r){
            if(mp[node(k[i].r,0)]) ans++;
            mp[node(k[i].r,0)] --;
        }
    }
    printf("%d\n",ans);

    return 0;
}
