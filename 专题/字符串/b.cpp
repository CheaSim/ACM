#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
//head

const int maxn = 4e4+10;
ull base[maxn],has[maxn];
void init(){
    base[0] = 1;
    rep(i,1,maxn) base[i] = base[i-1] * 131;
}
ull get_hash(int i,int L){
    return has[i] - has[i+L] * base[L];
}

int m,n;
char s[maxn];
int check(int len){
    map<ull,int> mx;
    int ans = -1;
    rep(i,0,n-len+1) {
        ull temp = get_hash(i,len);
        mx[temp] ++;
        if(mx[temp] >= m){
            ans = i;
        }
    }
    return ans;
}
int right_most = 0;
int res = 0;
void solve(int l,int r){
    int mid;
    while(l<=r){
        mid = l+r>>1;
        int temp = check(mid);
        if(temp != -1){
            l = mid + 1;
            res = mid;
            right_most = temp;
        }else{
            r = mid - 1;
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    init();
    while(scanf("%d",&m) && m){
        scanf("%s",s);
        n = strlen(s);
        has[n] = 0;
        per(i,0,n) has[i] = has[i+1] * 131 + s[i] - 'a' + 1;
        right_most = 0; res = 0;
        solve(1,n+1);
        if(res == 0){
            puts("none");
        }else{
            printf("%d %d\n",res,right_most);
        }
    }

    return 0;
}
