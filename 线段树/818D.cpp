#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
int n,A;
const int maxn = 1e6 + 10;
int vis[maxn];
int main(){
#ifdef LOCAL
    //freopen("1123.in","r",stdin);
#endif // LOCAL
    scanf("%d%d",&n,&A);
    int cnt = 0;
    rep(i,0,n){
        int x;scanf("%d",&x);
        if(x == A){
            cnt++;
            continue;
        }
        if(vis[x] < cnt) continue;
        vis[x] = vis[x]+1;
    }
    bool flag = 1;
    if(cnt==0){
        int i = 1;
        while(i == A){
            i++;
        }
        cout<<i<<endl;
        return 0;
    }
    rep(i,1,n){
        //cout<<vis[i]<<' ';
        if(vis[i]>=cnt){
            printf("%d ",i);
            return 0;
        }
    }
    if(flag) puts("-1");
    else puts("");
    return 0;
}
