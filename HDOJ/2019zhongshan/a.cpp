#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
const int maxn = 5000100;
int a[maxn];
int n;
int main(){
    while(~scanf("%d",&n)){
        rep(i,0,n) 
            scanf("%d",a+i);
        bool flag = false;
        rep(i,0,n-2){
            if(a[i] > a[i+2] - a[i+1]){
                flag = true;
                break;
            }
        }
        if(flag) 
            puts("YES");
        else 
            puts("NO");
    }
    return 0;
}
