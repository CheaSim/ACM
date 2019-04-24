#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N = 1e5 + 10;
char str[N];
char tmp[1005];
int bef[27];
int d[27][N];
int t;
int ans;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf(" %s",str);
    int len = strlen(str);
    memset(bef,-1,sizeof(d));
    for(int i=0;i<len;i++){
        bef[str[i] -'a'] = i;
        for(int j=0;j<26;j++){
            d[j][i] = bef[j];
           // cout<<bef[j]<<' ';
        }
       // cout<<endl;
    }

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf(" %s",tmp);
        int len_tmp = strlen(tmp);
        //cout<<len_tmp<<endl;
        int now = len - 1;
        int j;
        for(j=len_tmp - 1;j>=0 && now >= 0;j--){
            int c = (int)(tmp[j] - 'a');
            now = d[c][now];
           // cout<<c<<"->"<<now<<endl;
        }
        if(j < 0) puts("YES");
        else puts("NO");
    }
    return 0;
}
