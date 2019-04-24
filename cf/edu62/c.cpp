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
const int maxn = 3e5+10;
struct node{
    ll val, len;
    bool operator<(const node &x)const{
        if(val == x.val) return len > x.len;
        return val > x.val;
    }
}song[maxn];
int n,k;
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    ll mmax = 0;
    rep(i,0,n){
        scanf("%lld%lld",&song[i].len,&song[i].val);
        mmax = max(song[i].val,mmax);
    }
    sort(song,song+n);
    int cnt = 0;
    multiset<ll> s;
    ll ans = 0;
    ll sum = 0;
    per(i,1,mmax+1){
        if(i != song[cnt].val) continue;
        while(song[cnt].val == i) {
            s.insert(song[cnt].len);
            if(s.size() > k) sum -= (*s.begin()),s.erase(s.begin());
            sum += song[cnt].len;
            cnt++;
        }
        ans = max(ans,sum*i);
    }
    printf("%lld\n",ans);
    return 0;
}
