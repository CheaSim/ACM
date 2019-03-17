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

int n;
vector<int> ve;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,0,n){
        int l,r;scanf("%d%d",&l,&r);
        ve.push_back(r);
    }
    int page; scanf("%d",&page);
    int idx = lower_bound(ve.begin(),ve.end(),page) - ve.begin();
    printf("%d\n",n-idx);

    return 0;
}
