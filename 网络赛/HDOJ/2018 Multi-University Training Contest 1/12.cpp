#include<bits/stdc++.h>
#define LL long long
using namespace std;
int T,h,m,c;
char op;
double d;
int Sign;
char s[10];
int main() {
    cin >> T;
    while(T--){
        scanf("%d%d%s",&h,&m,s);
        Sign = (s[3] == '+') ? 1 : -1;
        h = h * 60 + m;
        sscanf(s + 4, "%lf", &d);
        c = (int)(d * 10 + 0.1);
        c = Sign * c * 6 - 8 * 60;
        h += c;
        h %= (24 * 60);
        if(h < 0)
            h += 24 * 60;
        printf("%02d:%02d\n",h/60,h%60);

    }
    return 0;
}
