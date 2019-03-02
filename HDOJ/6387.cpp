#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head
int m;
char ch;
int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        vector<int> p[3];
        int n = 0;
        rep(i,0,m){
            int pos; scanf("%d%c",&pos,ch);
            p[ch-'A'].pb(pos);
            n = max(n,pos);
        }
        rep(len,3,n+3){
            rep(j,0,3){
                int l = 0,r = len;
                while(l<n){
                    vector<int>::iterator  pos = p[j].upper_bound(l)-p[j];
                    
                }
            }
        }
    }

    return 0;
}
