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
const int maxk = 30;
int n,k,m;
char magic[10] = "ABAABB";
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    rep(test_case,1,T+1){
        scanf("%d%d%d",&n,&m,&k);
        bool flag = false;
        if(n!=m){
            if(k==1) flag = true;
            if(k==2 && m<8) flag = true;
            if(k>=3 && m<=2) flag = true;
            if(n<m) flag = true;
            if(m==7 && n==8 && k==2){
                printf("Case #%d:\n",test_case);
                puts("AABABBAA");
                continue;
            }
        }
        printf("Case #%d:\n",test_case);
        if(flag) puts("Impossible");
        if(n==m){
            rep(i,0,n) printf("A");
            puts("");
        }else if(k==2){
            int cnt = m-8;
            rep(i,0,cnt) printf("A");
            rep(i,0,n-cnt) printf("%c",magic[i%6]);
            puts("");
        }else{
            vector<char> ve;
            rep(i,0,m-3) printf("A");
            rep(i,0,3) ve.push_back('A'+i);
            rep(i,0,n-m+3){
                printf("%c",ve[i%3]);
            }
            puts("");
        }
    }
    return 0;
}
