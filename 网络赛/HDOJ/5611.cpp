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
char s[30];
ll a,b;
int month[30] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
#ifdef LOCAL
    freopen("2.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%lld%lld",&a,&b);
        ll ans = 0;
        rep(zzz,0,n){
            scanf("%s",s);
            char x = s[10];
            int i=0;
            for(i=6;i<11;i++){
                if(s[i]!=x) break;
            }
            if(i==11){
                ans += a;
                continue;
            }
            for(i=6;i<10;i++){
                if(s[i]!=s[i+1]+1) break;
            }
            if(i==10){
                ans += a;
                continue;
            }
            for(i=6;i<10;i++){
                if(s[i]!=s[i+1]-1) break;
            }
            if(i==10){
                ans += a;
                continue;
            }
            int y,m,d;
            y = (s[3]-'0')*1000 + (s[4]-'0')*100 + (s[5]-'0')*10+(s[6]-'0');
            m = (s[7]-'0')*10 + s[8]-'0';
            d = (s[9]-'0')*10 + s[10]-'0';
            bool f=0;
            if(y<=2016 && y>=1980){
                if(m>=1 && m<=12){
                    int temp = month[m];
                    if(y%4==0 && m==2){
                        temp++;
                    }
                    if(d>=1 && d<=temp){
                        ans += a;
                        f = 1;
                    }
                }
            }
            if(!f) ans += b;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
