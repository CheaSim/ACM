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

int mx[100];
bool check(int t[100]){
    rep(i,0,6){
        int x = t[i*4+1];
        rep(j,i*4+1,i*4+5){
            if(t[j] != x) return false;
        }
    }
    return true;
}
int solve(int mx[100],int go[30]){
    if(check(mx)) return true;
    int temp[100]= {0};
    memcpy(temp,mx,sizeof(temp));
    int t1 = temp[go[0]] ,t2 = temp[go[1]];
    for(int x = 0;x<6;x+=2){
        temp[go[x]] = temp[go[x+2]];
        temp[go[x+1]] = temp[go[x+3]];
    }
    temp[go[6]] = t1;temp[go[7]] = t2;
    return check(temp);
}
int go[6][30] = {{21,22, 12,11 ,17,18, 1,2},
                  {2,4, 6,8, 10,12, 14,16},
                 {15,16, 21,23 , 6,5 ,20,18},
                 {23,24, 10,9, 19,20, 3,4},
                  {1,3,5,7,9,11,13,15},
                  {13,14,22,24,8,7,19,17}};
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        rep(i,1,24+1) scanf("%d",mx+i);
        int ans = 0;
        rep(i,0,6) ans = ans|solve(mx,go[i]);
        if(ans) puts("YES");
        else puts("NO");
    }

    return 0;
}
