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
const int maxn = 5e3+10;
int c[maxn];
int a[maxn];
int t1,t2,t3,t4;
int ans1,ans2,ans3,ans4;
int vis[maxn];
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    scanf("%s",s);
    rep(i,0,n) c[i] = s[i] - '0';
    scanf("%s",s);
    rep(i,0,n) a[i] = s[i] - '0';

    rep(i,0,n) {
        if(c[i] == 0 && a[i] == 0) t1++,vis[i] = 1;
        if(c[i] == 1 && a[i] == 0) t2++,vis[i] = 2;
        if(c[i] == 0 && a[i] == 1) t3++,vis[i] = 3;
        if(c[i] == 1 && a[i] == 1) t4++,vis[i] = 4;
    }
    bool flag = false;
    rep(x,0,t2+1){
        if(flag) break;
        rep(y,0,t3+1){
            if(flag) break;
            if(x+y>n/2 || t2-x+t3-y>n/2) continue;
            if(abs(x-t3+y) > t4) continue;
            ans2 = x;
            ans3 = y;
            if(x-t3+y<0){
                ans4 = t4 - abs(x-t3+y);
                if(ans4&1) continue;
                ans4 /= 2;
                ans4 += abs(x-t3+y);
            }else{
                ans4 = t4 - abs(x-t3+y);
                if(ans4&1) continue;
                ans4 /= 2;
            }
            ans1 = n/2 - ans3 - ans2 - ans4;
            if(ans1 > t1 || ans1 < 0) continue;
            if(ans4 > t4 || ans4 < 0) continue;
            flag = true;
        }
    }
    if(!flag){
        puts("-1");
        return 0;
    }

    vector<int>ans;
    ans.push_back(0);
    ans.push_back(ans1);
    ans.push_back(ans2);
    ans.push_back(ans3);
    ans.push_back(ans4);
    rep(i,0,n){
        int x = vis[i] ;
        if(ans[x]){
            printf("%d ",i+1);
            ans[x]--;
        }
    }
    return 0;
}
