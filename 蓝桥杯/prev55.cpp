#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
typedef  long long ull;
const int INF = 0x3f3f3f3f;
//head
int n;
const int maxchar = 100;
const int maxn = 100;
char s[maxn];
int k;
char ans[maxn];
void solve(ull x){
    memset(ans,0,sizeof(ans));
    ull t = k;
    int cnt = 0;
    if(x==0) ans[0] = '0';
    while(x){
        if(x%t < 10){
            ans[cnt++] = x%t+'0';
        }else{
            ans[cnt++] = x%t+'A'-10;
        }
        x/=t;
    }
    int len = strlen(ans);
    rep(i,0,len/2) swap(ans[i],ans[len-1-i]);
}
char tt[maxn];
ull real_num(){
    int len = strlen(tt);
    ull t = 0;
    ull cnt = 1;
    per(i,0,len){
        if(tt[i]>='A' && tt[i]<='Z'){
            t += cnt * (tt[i] - 'A' +10);
        }else{
            t += cnt * (tt[i] - '0');
        }
        cnt*= k;
    }
    return t;
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    cin>>n;
    ull now = 0;
    int sign = 0;
    k = 10;
    bool init = false;
    rep(i,0,n){
        cin>>s;
        if(s[0] == 'C' && s[1] == 'L') {
            now = 0;
            init = true;
        }else if(s[0] == 'N'){
            cin>>tt;
            ull temp = real_num();
            if(init){
                now = temp;
                init = false;
                continue;
            }
            if(sign == 1) now += temp;
            else if(sign == 2) now -= temp;
            else if(sign == 3) now *= temp;
            else if(sign == 4) now /= temp;
            else now %= temp;
        }else if(s[0] == 'A'){
            sign = 1;
        }else if(s[0] == 'S'){
            sign = 2;
        }else if(s[0] == 'M' && s[1] == 'U'){
            sign = 3;
        }else if(s[0] == 'D'){
            sign = 4;
        }else if(s[0] == 'M'){
            sign = 5;
        }else if(s[0] == 'E'){
            solve(now);
            cout<<ans<<'\n';
        }else{
            cin>>k;
        }
    }
    return 0;
}
