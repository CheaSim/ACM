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
//
//

const int maxn = 5e5+10;
int n;
char s[maxn];
int t1[maxn],t2[maxn];
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    scanf("%d",&n);
    int cnt = 0;
    rep(i,0,n){
        cin>>s;
        int len = strlen(s);
        int l,r;
        rep(j,0,len){
            if(s[j] == '('){
                l++;
            }else{
                if(l) l--;
                else r++;
            }
        }
        if(l==0 || r==0){
            if(l) t1[l]++;
            if(r) t2[r]++;
        }
        if(l==0 && r==0) cnt++;
    }
    int ans = 0;
    ans += cnt/2;
    rep(i,0,maxn){
        ans += min(t1[i],t2[i]);
    }
    printf("%d\n",ans);


    return 0;
}
